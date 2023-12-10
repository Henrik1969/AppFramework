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
#include <fstream>  // Include for std::ofstream
#include <nlohmann/json.hpp>  // Include for JSON handling
#include "Argument.hpp" 
#include "ArgumentConfig.hpp"
#include "DefaultSettings.hpp"
#include "Version.hpp"
#include "ConfigManager.hpp"

std::vector<ArgumentData> argumentDefinitions = {
    {"--help", "-h", "Display help information", true, false, E_Argument_ValueType::None},
    {"--version", "-v", "Display version information", true, false, E_Argument_ValueType::None},
    {"--dumpconfig", "-D", "Dumps the default settings to config.json", true, false, E_Argument_ValueType::None}
    // Add other arguments here
};
void handleHelp(const std::shared_ptr<Argument>& arg) {
    std::cout << "Help requested: " << arg->getDescription() << std::endl;

    // Print the command-line options and their descriptions
    std::cout << "Available command-line options:" << std::endl;
    for (const auto& argData : argumentDefinitions) {
        std::cout << "  " << argData.longName << ", " << argData.shortName << "\n    " << argData.description << std::endl;
    }
    exit(0);
}

void handleVersion(const std::shared_ptr<Argument>& arg) {
	std::cout << VERSION << std::endl;
	exit(0);
}

void handleDumpConfig(const std::shared_ptr<Argument>& arg) {
    dumpDefaultConfig();
    exit(0); // You might want to exit the program after dumping the config
}

void dumpDefaultConfig() {
    nlohmann::json defaultConfig = DefaultSettings::getDefaultConfig();
    std::ofstream configFile("config.json");
    configFile << defaultConfig.dump(4); // '4' for pretty printing
    configFile.close();

    std::cout << "Default configuration dumped to config.json" << std::endl;
}

std::map<std::string, Argument> ArgumentConfig::getDefinedArguments() {
    std::map<std::string, Argument> definedArgs;
    for (const auto& argData : argumentDefinitions) {
        definedArgs.emplace(argData.longName, Argument(argData));
    }
    return definedArgs;
}

void ArgumentConfig::setupArguments(CommandLineProcessor& cmdProcessor) {
    // Define your arguments
    Argument helpArg("--help", "-h", "Display help information", true, false, E_Argument_ValueType::None);
    Argument versionArg("--version", "-v", "Display version information", true, false, E_Argument_ValueType::None);
    Argument dumpConfigArg("--dumpconfig", "-D", "Dumps the default settings to config.json", true, false, E_Argument_ValueType::None);

    // Add handler functions
    cmdProcessor.AddArgumentHandler(helpArg, handleHelp);
    cmdProcessor.AddArgumentHandler(versionArg, handleVersion);
	cmdProcessor.AddArgumentHandler(dumpConfigArg, handleDumpConfig);
    // ... other handlers ...
}
