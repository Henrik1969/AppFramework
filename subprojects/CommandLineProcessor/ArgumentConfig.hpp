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

// ArgumentConfig.hpp

#ifndef ARGUMENTCONFIG_HPP
#define ARGUMENTCONFIG_HPP

#include "Argument.hpp"
#include "CommandLineProcessor.hpp"
#include <iostream> // Include for std::cout
#include <memory>
#include <map>

void handleHelp(const std::shared_ptr<Argument>& arg);
void handleVersion(const std::shared_ptr<Argument>& arg);
void handleDumpConfig(const std::shared_ptr<Argument>& arg);
void dumpDefaultConfig();

class ArgumentConfig {
public:
    static std::map<std::string, Argument> getDefinedArguments();
    static void setupArguments(CommandLineProcessor& cmdProcessor);
};

#endif // ARGUMENTCONFIG_HPP