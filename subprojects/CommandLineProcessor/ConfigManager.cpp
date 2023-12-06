/*
  This file is part of the AppFramework project.

  AppFramework is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, GPL version 4.

  AppFramework is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License version 4 for more details.

  You should have received a copy of the GNU General Public License
  along with AppFramework. If not, see <https://www.gnu.org/licenses/>.
*/

// ConfigManager.cpp

#include "Arguments.hpp"
#include "ConfigManager.hpp"
#include "Logger.hpp"
#include <DefaultSettings.hpp>
#include <nlohmann/json.hpp> 
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef THREAD_SAFE
std::mutex ConfigManager::mtx;
#endif//

ConfigManager::ConfigManager(const std::string& configFilePath, const Arguments& cmdArgs):filePath(configFilePath),cmdArgs(cmdArgs) 
{
    std::ifstream file(filePath);
    if (file) {
        try {
            file >> config;
        } catch (const nlohmann::json::parse_error& e) {
            Logger::getInstance().log("JSON parsing error: " + std::string(e.what()), "ConfigManager::ConfigManager", Logger::Severity::Error);
            std::cerr << "Configuration loading error. Check log file for details." << std::endl;
            config = nlohmann::json::object(); // Ensure config is a valid JSON object
        }
    } else {
        Logger::getInstance().log("Config file not found: " + filePath, "ConfigManager::ConfigManager", Logger::Severity::Warning);
        std::cerr << "Configuration file missing. A new one will be created." << std::endl;
        config = nlohmann::json::object(); // Initialize config as an empty object
    }

    // Additional check to ensure config is not null
    if (config.is_null()) {
        config = nlohmann::json::object();
    }

    // Parse and store command line arguments from cmdArgs
    for (const auto& argPair : cmdArgs.getArgValues()) {
        std::string key = argPair.first;
        std::string value = argPair.second;
        commandLineArgs[key] = value;
    }
    applyDefaults();
}

ConfigManager::~ConfigManager() {
    sync();
}

void ConfigManager::parseCommandLineArgs(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.size() >= 2 && arg.substr(0, 2) == "--") {
            // This is a command line argument of the form "--key=value"
            size_t equalPos = arg.find('=');
            if (equalPos != std::string::npos) {
                std::string key = arg.substr(2, equalPos - 2);
                std::string value = arg.substr(equalPos + 1);
                commandLineArgs[key] = value;
            }
        }
    }
}

template<typename T>
T ConfigManager::get(const std::string& key) const {
#ifdef THREAD_SAFE
    std::lock_guard<std::mutex> lock(mtx);
#endif
    // Check if a command line argument exists and has a value for the key
    if (commandLineArgs.find(key) != commandLineArgs.end()) {
        std::istringstream valueStream(commandLineArgs.at(key));
        T typedValue;
        valueStream >> typedValue;
        return typedValue;
    }

    try {
        const nlohmann::json& ref = getRefToValue(key, true);
        return ref.get<T>();
    } catch (const nlohmann::json::out_of_range& e) {
        // Handle the case where the key does not exist
        Logger::getInstance().log("Key not found in configuration: " + key, "ConfigManager::get", Logger::Severity::Warning);
        throw std::runtime_error("Configuration key not found: " + key);
    } catch (const nlohmann::json::exception& e) {
        // Handle other JSON exceptions
        Logger::getInstance().log("Error accessing key '" + key + "': " + e.what(), "ConfigManager::get", Logger::Severity::Error);
        throw;
    }
}

template<typename T>
void ConfigManager::set(const std::string& key, const T& value) {
#ifdef THREAD_SAFE
    std::lock_guard<std::mutex> lock(mtx);
#endif
    nlohmann::json& ref = getRefToValue(key); // Use non-const ref
    ref = value;
}

void ConfigManager::sync() {
#ifdef THREAD_SAFE
    std::lock_guard<std::mutex> lock(mtx);
#endif
    std::ofstream file(filePath);
    if (file) {
        file << config.dump(4);  // Save the JSON in a pretty format
    }
}

// Function to apply default settings
void ConfigManager::applyDefaults() {
    // Get default settings
    auto defaultConfig = DefaultSettings::getDefaultConfig();

    // Apply default settings for GTK and window size
	if (!cmdArgs.isInArgs("--gtk-module")) {
        set("gtk.module", defaultConfig["gtk"]["module"].get<std::string>());
    }
    if (!cmdArgs.isInArgs("--gtk-window-width")) {
        set("window.width", defaultConfig["window"]["width"].get<int>());
    }
    // ... and so on for other settings ...
}

const nlohmann::json& ConfigManager::getRefToValue(const std::string& key, bool forRead) const {
    const nlohmann::json* j = &config;
    std::istringstream iss(key);
    std::string token;
    while (std::getline(iss, token, '.')) {
        j = &((*j).at(token));
    }
    return *j;
}

nlohmann::json& ConfigManager::getRefToValue(const std::string& key) {
    nlohmann::json* j = &config;
    std::istringstream iss(key);
    std::string token;
    while (std::getline(iss, token, '.')) {
        j = &((*j)[token]);
    }
    return *j;
}

// Explicit template instantiation
template int ConfigManager::get<int>(const std::string& key) const;
template std::string ConfigManager::get<std::string>(const std::string& key) const;
template void ConfigManager::set<int>(const std::string& key, const int& value);
template void ConfigManager::set<std::string>(const std::string& key, const std::string& value);
