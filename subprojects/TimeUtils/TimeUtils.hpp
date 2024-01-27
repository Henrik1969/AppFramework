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

// TimeUtils.hpp

#ifndef TIMEUTILS_HPP
#define TIMEUTILS_HPP

#include <string>
#include <chrono>

namespace TimeUtils {
    std::string getCurrentTimestamp();
    std::string getCurrentTimestamp(const std::string& timeFormat);
    std::chrono::system_clock::time_point parseTimestamp(const std::string& timestamp, const std::string& timeFormat);
    std::chrono::seconds calculateTimeDifference(const std::string& timestamp1, const std::string& timestamp2, const std::string& timeFormat);

    // DTG Format Functions
    std::string toDTGFormat(const std::chrono::system_clock::time_point& timePoint, const char timeZone);
    std::chrono::system_clock::time_point fromDTGFormat(const std::string& dtgString);
    std::string getCurrentDTG(const char timeZone);

} // namespace TimeUtils

#endif // TIMEUTILS_HPP
