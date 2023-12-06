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

#include <iostream>
#include "ArgumentConfig.hpp"
#include "DefaultSettings.hpp"
#include "Version.hpp"

void handleHelp(const std::shared_ptr<Argument>& arg) {
    std::cout << "Help requested: " << arg->getDescription() << std::endl;
}

void handleVersion(const std::shared_ptr<Argument>& arg) {
	std::cout << VERSION << std::endl;
}

void handleConfig(const std::shared_ptr<Argument>& arg) {
	#ifdef ENABLE_DEBUG
    std::cout << "Config requested. ";
    std::cout << "Long Name: " << arg->getLongName() << ", ";
    std::cout << "Short Name: " << arg->getShortName() << ", ";
    std::cout << "Value: " << arg->getValue<std::string>() << std::endl;
    #endif //ENABLE_DEBUG
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
    
    // Add default GTK options as arguments
    // Assume we have a way to iterate through DefaultSettings to add them
    auto defaultGtkSettings = DefaultSettings::getDefaultConfig()["gtk"];
    for (const auto& setting : defaultGtkSettings.items()) {
        // Create Argument objects for each GTK setting and add them to the processor
        Argument gtkArg("--gtk-" + setting.key(), "", "GTK default setting for " + setting.key(), true, E_Argument_ValueType::String);
        cmdProcessor.AddArgumentHandler(gtkArg, [](const std::shared_ptr<Argument>& arg) {
            // Handler logic for GTK arguments can be defined here if needed
        });
    }

    // Add handler functions
    cmdProcessor.AddArgumentHandler(helpArg, handleHelp);
    cmdProcessor.AddArgumentHandler(versionArg, handleVersion);
    cmdProcessor.AddArgumentHandler(configArg, handleConfig);
    // ... other handlers ...
}