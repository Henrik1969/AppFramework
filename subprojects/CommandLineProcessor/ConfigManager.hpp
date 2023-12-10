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

// ConfigManager.hpp

#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include "Arguments.hpp"
#include <iostream>
#include <string>
#include <mutex>
#include <nlohmann/json.hpp>
#include <unordered_map>

class ConfigManager {
public:
    ConfigManager(const std::string& configFilePath, const Arguments& cmdArgs);
    ~ConfigManager();

    void applyDefaults();
	void mergeJson(nlohmann::json& base, const nlohmann::json& update);

    template<typename T>
    T get(const std::string& key) const;

    template<typename T>
    void set(const std::string& key, const T& value);

    void sync();

private:
    const Arguments& cmdArgs; // Reference to an Arguments instance
    nlohmann::json config;
    std::string filePath;
    
    const nlohmann::json& getRefToValue(const std::string& key, bool forRead) const;
    nlohmann::json& getRefToValue(const std::string& key);

    std::unordered_map<std::string, std::string> commandLineArgs; // Store command line arguments

    void parseCommandLineArgs(int argc, char** argv);
    
#ifdef THREAD_SAFE
    static std::mutex mtx;
#endif
};

#endif // CONFIGMANAGER_HPP
