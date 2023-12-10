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

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "Logger.hpp"
#include "DefaultSettings.hpp" 
#include "EnvVar.hpp"
#include "StringUtils.hpp"
#include "TimeUtils.hpp"

Logger::Logger() {
    // Fetch default log path from DefaultSettings
    std::string defaultLogPath = DefaultSettings::getDefaultConfig()["AppFramework"]["Config"]["Defaults"]["Logger"]["defaultLogPath"];
    
    std::string logPath = defaultLogPath; // Use default log path

    // Use std::getenv directly to avoid dependency on EnvVar
    const char* configPath = std::getenv("LOGPATH");
    if (configPath != nullptr) {
        logPath = std::string(configPath) + "/" + defaultLogPath;
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

void Logger::log(const std::string& message, const std::string& location, Logger::Severity severity) {
    if (logFile.is_open()) {
        // Fetch the time format and log entry format from DefaultSettings
        std::string timeFormat = DefaultSettings::getDefaultConfig()["AppFramework"]["Config"]["Defaults"]["Logger"]["timeFormat"];
        std::string logEntryFormat = DefaultSettings::getDefaultConfig()["AppFramework"]["Config"]["Defaults"]["Logger"]["logEntryFormat"];

        // Get the current timestamp in the specified format
        auto now = std::chrono::system_clock::now();
        auto now_time_t = std::chrono::system_clock::to_time_t(now);
        std::tm now_localtime = *std::localtime(&now_time_t);
        std::stringstream timestamp;
        timestamp << std::put_time(&now_localtime, timeFormat.c_str());

        // Replace placeholders in the log entry format
        StringUtils::replaceAll(logEntryFormat, "%timestamp%", timestamp.str());
        StringUtils::replaceAll(logEntryFormat, "%level%", severityToString(severity));
        StringUtils::replaceAll(logEntryFormat, "%location%", location);
        StringUtils::replaceAll(logEntryFormat, "%message%", message);

        // Write the formatted log entry
        logFile << logEntryFormat << std::endl;
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

std::string Logger::formatMessage(const std::string& message, Severity severity, const std::string& location) {
    // Fetch default log entry format and time format
    std::string defaultLogEntryFormat = DefaultSettings::getDefaultConfig()["AppFramework"]["Config"]["Defaults"]["Logger"]["logEntryFormat"];
    std::string timeFormat = DefaultSettings::getDefaultConfig()["AppFramework"]["Config"]["Defaults"]["Logger"]["timeFormat"];

    // Format the message using the default format
    std::string formattedMessage = defaultLogEntryFormat;
    StringUtils::replaceAll(formattedMessage, "%timestamp%", TimeUtils::getCurrentTimestamp(timeFormat));
    StringUtils::replaceAll(formattedMessage, "%level%", severityToString(severity));
    StringUtils::replaceAll(formattedMessage, "%message%", message);
    StringUtils::replaceAll(formattedMessage, "%location%", location);

    return formattedMessage;
}