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

#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP

#include "Argument.hpp"
#include <string>
#include <map>
#include <stdexcept>

class Arguments {
public:
    Arguments(int argc, char* argv[], const std::map<std::string, Argument>& definedArgs);

    const std::map<std::string, std::string>& getArgValues() const { return argValues; }
    std::string getArgValue(const std::string& argName) const;
    bool isInArgs(const std::string& str) const;

private:
    std::map<std::string, std::string> argValues; // Maps argument names to their values
};

#endif // ARGUMENTS_HPP

