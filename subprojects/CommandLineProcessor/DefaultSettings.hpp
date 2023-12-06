/*
  This file is part of the AppEssential project.

  AppEssential is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, GPL version 4.

  AppEssential is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License version 4 for more details.

  You should have received a copy of the GNU General Public License
  along with AppEssential. If not, see <https://www.gnu.org/licenses/>.
*/

//DefaultSettings.hpp

#ifndef DEFAULTSETTINGS_HPP
#define DEFAULTSETTINGS_HPP

#include <nlohmann/json.hpp>

class DefaultSettings {
public:
    static const nlohmann::json defaultConfig;
    static const nlohmann::json getDefaultConfig();
};

#endif // DEFAULTSETTINGS_HPP
