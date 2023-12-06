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

// Arguments.cpp

#include <iostream>
#include "Arguments.hpp"

Arguments::Arguments(int argc, char* argv[], const std::map<std::string, Argument>& definedArgs) {
    for (const auto& argPair : definedArgs) {
        if (argPair.second.hasDefaultValue()) {
            argValues[argPair.first] = argPair.second.getDefaultValue();
        }
    }

    for (int i = 1; i < argc; ++i) {
        std::string currentArg = argv[i];
        auto it = definedArgs.find(currentArg);

        if (it == definedArgs.end()) {
            for (const auto& argPair : definedArgs) {
                if (argPair.second.getShortName() == currentArg) {
                    it = definedArgs.find(argPair.second.getLongName());
                    break;
                }
            }
        }

        if (it != definedArgs.end()) {
            const Argument& arg = it->second;

            if (arg.needsValue()) {
                if (i + 1 < argc) {
                    argValues[it->first] = argv[i + 1];
                    ++i;
                } else {
                    throw std::runtime_error("Missing argument value for " + currentArg);
                }
            } else {
                argValues[it->first] = "";
            }
        } else {
            throw std::runtime_error("Unknown argument " + currentArg);
        }
    }
}

std::string Arguments::getArgValue(const std::string& argName) const {
    auto it = argValues.find(argName);
    if (it != argValues.end()) {
        return it->second;
    }
    return "";
}

bool Arguments::isInArgs(const std::string& str) const {
    return argValues.find(str) != argValues.end();
}

std::vector<std::string> Arguments::getGtkArguments() const {
    std::vector<std::string> gtkArgs;

    for (const auto& argPair : argValues) {
        const std::string& arg = argPair.first;

        // Check if the argument is a GTK argument
        if (arg.find("--gtk-") == 0) {
            // Construct the argument string as it would appear on the command line
            std::string argStr = arg + (argPair.second.empty() ? "" : "=" + argPair.second);
            gtkArgs.push_back(argStr);
        }
    }

    return gtkArgs;
}