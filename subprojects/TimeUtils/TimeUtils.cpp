#include "TimeUtils.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>

namespace TimeUtils {
    std::string getCurrentTimestamp() {
        return getCurrentTimestamp("%Y-%m-%d %H:%M:%S");
    }

    std::string getCurrentTimestamp(const std::string& timeFormat) {
        auto now = std::chrono::system_clock::now();
        auto now_time_t = std::chrono::system_clock::to_time_t(now);
        auto now_localtime = *std::localtime(&now_time_t);

        std::ostringstream timestampStream;
        timestampStream << std::put_time(&now_localtime, timeFormat.c_str());
        return timestampStream.str();
    }

    std::chrono::system_clock::time_point parseTimestamp(const std::string& timestamp, const std::string& timeFormat) {
        std::tm tm = {};
        std::istringstream timestampStream(timestamp);
        timestampStream >> std::get_time(&tm, timeFormat.c_str());

        if (timestampStream.fail()) {
            throw std::invalid_argument("Invalid timestamp or format.");
        }

        std::time_t time = std::mktime(&tm);
        return std::chrono::system_clock::from_time_t(time);
    }

    std::chrono::seconds calculateTimeDifference(const std::string& timestamp1, const std::string& timestamp2, const std::string& timeFormat) {
        std::chrono::system_clock::time_point time1 = parseTimestamp(timestamp1, timeFormat);
        std::chrono::system_clock::time_point time2 = parseTimestamp(timestamp2, timeFormat);

        std::chrono::seconds difference = std::chrono::duration_cast<std::chrono::seconds>(time2 - time1);
        return difference;
    }
} // namespace TimeUtils
