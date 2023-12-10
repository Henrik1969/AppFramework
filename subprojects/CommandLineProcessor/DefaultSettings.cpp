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

//DefaultSettings.cpp

#include "DefaultSettings.hpp"

//=============================================================================
// Write your default hardcoded configs here in json format
//=============================================================================
const nlohmann::json DefaultSettings::defaultConfig = {
    {"AppFramework", {
        {"Config", {
            {"Defaults", {
                {"gtk", {
                    {"module", "default_module"},
                    {"window", {
                        {"height", 600},
                        {"pos_x", 500},
                        {"pos_y", 500},
                        {"width", 800},
                        {"title", "AppFramework test"}
                    }}
                }},
                {"Logger", {
                    {"defaultLogPath", "testing.log"},
                    {"logEntryFormat", "[%timestamp%] [%level%] %location%: %message%"},
                    {"timeFormat", "%Y-%m-%d %H:%M:%S"}
                }}
                // ... other default settings ...
            }}
        }}
    }}
};
//=============================================================================
//
//=============================================================================

const nlohmann::json DefaultSettings::getDefaultConfig() {
    return defaultConfig;
}