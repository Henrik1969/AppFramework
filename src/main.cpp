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

// main.cpp

#include <iostream>
#include "EnvVar.hpp"
#include "ConfigManager.hpp"
#include "Logger.hpp"
#include "Argument.hpp"
#include "Arguments.hpp"
#include "CommandLineProcessor.hpp"

void handleHelp(const std::shared_ptr<Argument>& arg) {
    std::cout << "Help requested: " << arg->getDescription() << std::endl;
}

void handleVersion(const std::shared_ptr<Argument>& arg) {
    std::cout << "Version requested: " << arg->getDescription() << std::endl;
}


int main(int argc, char* argv[]) {


    // Initialize Arguments instance
    Arguments cmdArgs(argc, argv);

    // Initialize CommandLineProcessor with Arguments instance
    CommandLineProcessor cmdProcessor(cmdArgs);

    // Define arguments and add to processor
    Argument helpArg("--help", "-h", "Display help information", false, E_Argument_ValueType::None);
    Argument versionArg("--version", "-v", "Display version information", false, E_Argument_ValueType::None);
    cmdProcessor.AddArgumentHandler(helpArg, handleHelp);
    cmdProcessor.AddArgumentHandler(versionArg, handleVersion);

    // Process the command line arguments
    cmdProcessor.Process();
    

/*
    std::string configFile = args.getConfigFile();
    // Use configFile with ConfigManager

    std::string logFile = args.getLogFile();
    // Use logFile with Logger

    EnvVar myVar("LOGPATH");

    // Log using Logger after getting environment variable
    std::string logPathValue = myVar.get();
    Logger::getInstance().log("LOGPATH value: " + logPathValue, "main", Logger::Severity::Info);
    std::cout << "LOGPATH: " << logPathValue << std::endl;


    //test for the ConfigManager class

    ConfigManager configManager("config.json");

    // Retrieve the nested value for "foo.bar.doo.tar"
    try {
        std::string value = configManager.get<std::string>("foo.bar.doo.tar");
        std::cout << "Value of foo.bar.doo.tar: " << value << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error reading nested key: " << e.what() << std::endl;
    }

	std::cout<<"Hello, world!"<<std::endl;
*/
    return 0;
}