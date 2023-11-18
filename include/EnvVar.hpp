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

// EnvVar.hpp

#ifndef ENVVAR_HPP
#define ENVVAR_HPP

#include <string>
#include <optional>
#ifdef THREAD_SAFE
#include <mutex>
#endif

class EnvVar {
public:
    explicit EnvVar(const std::string& name);
    
    std::string get() const;
    bool set(const std::string& value) const;
    void store();
    bool restore() const;

private:
    std::string varName;
    std::optional<std::string> storedValue;
#ifdef THREAD_SAFE
    static std::mutex mtx;  // Mutex for thread safety
#endif
};

#endif // ENVVAR_HPP

