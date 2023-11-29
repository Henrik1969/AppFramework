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

#include "DefaultSettings.hpp"

const nlohmann::json DefaultSettings::defaultConfig = {
//=============================================================================
// Write your default hardcoded configs here in json format
//=============================================================================
    {"AppFramework", {
        {"Config", {
            {"Defaults", {
                {"Bg", "Lime"}
                // Add more nested settings as needed
            }}
        }}
    }}
//=============================================================================
//
//=============================================================================

};

const nlohmann::json DefaultSettings::getDefaultConfig() {
    return defaultConfig;
}