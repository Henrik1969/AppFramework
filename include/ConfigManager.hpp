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

#include <iostream>
#include <string>
#include <mutex>
#include <nlohmann/json.hpp>

class ConfigManager {
public:
    explicit ConfigManager(const std::string& configFilePath);
    ~ConfigManager();

    template<typename T>
    T get(const std::string& key) const;

    template<typename T>
    void set(const std::string& key, const T& value);

    void sync();

#ifdef THREAD_SAFE
    static std::mutex mtx;  // Mutex for thread safety
#endif

private:
    nlohmann::json config;
    std::string filePath;
    const nlohmann::json& getRefToValue(const std::string& key, bool forRead) const;
    nlohmann::json& getRefToValue(const std::string& key);
};

#endif // CONFIGMANAGER_HPP
