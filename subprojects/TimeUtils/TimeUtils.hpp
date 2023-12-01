#ifndef TIMEUTILS_HPP
#define TIMEUTILS_HPP

#include <string>
#include <chrono>

namespace TimeUtils {
    std::string getCurrentTimestamp();
    std::string getCurrentTimestamp(const std::string& timeFormat);
    std::chrono::system_clock::time_point parseTimestamp(const std::string& timestamp, const std::string& timeFormat);
    std::chrono::seconds calculateTimeDifference(const std::string& timestamp1, const std::string& timestamp2, const std::string& timeFormat);
} // namespace TimeUtils

#endif // TIMEUTILS_HPP
