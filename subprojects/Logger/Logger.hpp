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

// Logger.hpp

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <mutex>

class Logger {
public:
    enum class Severity {
    	Trace,
    	Debug,
        Info,
        Warning,
        Error,
        Fatal
    };

    static Logger& getInstance();
    void log(const std::string& message, const std::string& location, Severity severity);
    void setFormat(const std::string& format) {
        this->logFormat = format;
    }
    std::string formatMessage(const std::string& message, Severity severity, const std::string& location);
private:
    std::ofstream logFile;
    std::mutex mtx;

    Logger(); // Private constructor for Singleton pattern
    ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    std::string logFormat;
    std::string severityToString(Severity severity);
};

#endif // LOGGER_HPP
