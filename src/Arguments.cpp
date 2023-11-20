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
#include <iostream>
#include "Arguments.hpp"

Arguments::Arguments(int argc, char* argv[], const std::map<std::string, Argument>& definedArgs) {
    for (int i = 1; i < argc; ++i) {
        std::string currentArg = argv[i];
        std::cout << "Processing argument: " << currentArg << std::endl;

        // First, try to find the argument as is (works for long names)
        auto it = definedArgs.find(currentArg);
        if (it == definedArgs.end()) {
            // If not found, try to match it as a short name
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
                    argValues[it->first] = argv[i + 1]; // Use the long name as key
                    ++i; // Skip the value as it's already processed
                }
                // Optionally, add else part for error handling if value is expected but not provided
            } else {
                argValues[it->first] = ""; // No value needed, just mark as present
            }
        } else {
            std::cout << "Unrecognized argument: " << currentArg << std::endl;
        }
    }
}

std::string Arguments::getArgValue(const std::string& argName) const {
    auto it = argValues.find(argName);
    if (it != argValues.end()) {
        return it->second;
    }
    return ""; // Return empty string if argument not found
}

bool Arguments::isInArgs(const std::string& str) const {
    return argValues.find(str) != argValues.end();
}

