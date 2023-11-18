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

// EnvVar.cpp

#include "EnvVar.hpp"
#include "Logger.hpp"
#include <cstdlib>
#ifdef THREAD_SAFE
#include <mutex>
std::mutex EnvVar::mtx;  // Define the static mutex
#endif

EnvVar::EnvVar(const std::string& name) : varName(name) {}

std::string EnvVar::get() const {
#ifdef THREAD_SAFE
    std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex
#endif
    const char* value = std::getenv(varName.c_str());
    return (value != nullptr) ? std::string(value) : std::string();
}

bool EnvVar::set(const std::string& value) const {
#ifdef THREAD_SAFE
    std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex
#endif
    return setenv(varName.c_str(), value.c_str(), 1) == 0;
}

void EnvVar::store() {
#ifdef THREAD_SAFE
    std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex
#endif
    storedValue = get();
}

bool EnvVar::restore() const {
#ifdef THREAD_SAFE
    std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex
#endif
    if (storedValue.has_value()) {
        return set(storedValue.value());
    }
    return false;
}