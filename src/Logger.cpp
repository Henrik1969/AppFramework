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
// Logger.cpp

#include "Logger.hpp"
#include "EnvVar.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

Logger::Logger() {
    std::string logPath = "testing.log"; // Default log file name

    // Use std::getenv directly to avoid dependency on EnvVar
    const char* configPath = std::getenv("LOGPATH");
    if (configPath != nullptr) {
        logPath = std::string(configPath) + "/testing.log"; // Use the directory from LOGPATH
    }

    logFile.open(logPath, std::ios::out | std::ios::app);
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message, const std::string& location, Severity severity) {
    std::lock_guard<std::mutex> lock(mtx);

    // Get current time
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_localtime = *std::localtime(&now_time_t);

    if (logFile.is_open()) {
        logFile << "[" << std::put_time(&now_localtime, "%Y-%m-%d %H:%M:%S") << "] "
                << "[" << severityToString(severity) << "] "
                << location << ": " << message << std::endl;
    }
}

std::string Logger::severityToString(Severity severity) {
    switch (severity) {
    	case Severity::Trace:	return "TRACE";
    	case Severity::Debug:	return "DEBUG";
        case Severity::Info:	return "INFO";
        case Severity::Warning:	return "WARNING";
        case Severity::Error:	return "ERROR";
        case Severity::Fatal:	return "FATAL";
        default:
            return "UNKNOWN";
    }
}