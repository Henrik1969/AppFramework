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

// ArgumentConfig.cpp

#include "ArgumentConfig.hpp"

void handleHelp(const std::shared_ptr<Argument>& arg) {
    std::cout << "Help requested: " << arg->getDescription() << std::endl;
}

void handleVersion(const std::shared_ptr<Argument>& arg) {
    std::cout << "Version requested: " << arg->getDescription() << std::endl;
}

void handleConfig(const std::shared_ptr<Argument>& arg) {
    std::cout << "Config requested. ";
    std::cout << "Long Name: " << arg->getLongName() << ", ";
    std::cout << "Short Name: " << arg->getShortName() << ", ";
    std::cout << "Value: " << arg->getValue<std::string>() << std::endl;
}

std::map<std::string, Argument> ArgumentConfig::getDefinedArguments() {
    std::map<std::string, Argument> definedArgs;

    // Directly constructing Argument objects in the map using emplace
    definedArgs.emplace("--help", Argument("--help", "-h", "Display help information", false, E_Argument_ValueType::None));
    definedArgs.emplace("--version", Argument("--version", "-v", "Display version information", false, E_Argument_ValueType::None));
    definedArgs.emplace("--config", Argument("--config", "-c", "Specify config file", true, E_Argument_ValueType::String));
    // ... other Argument objects ...

    return definedArgs;
}

void ArgumentConfig::setupArguments(CommandLineProcessor& cmdProcessor) {
    // Define your arguments
    Argument helpArg("--help", "-h", "Display help information", false, E_Argument_ValueType::None);
    Argument versionArg("--version", "-v", "Display version information", false, E_Argument_ValueType::None);
    Argument configArg("--config", "-c", "Specify config file", true, E_Argument_ValueType::String);
    // ... other arguments ...

    // Add handler functions
    cmdProcessor.AddArgumentHandler(helpArg, handleHelp);
    cmdProcessor.AddArgumentHandler(versionArg, handleVersion);
    cmdProcessor.AddArgumentHandler(configArg, handleConfig);
    // ... other handlers ...
}