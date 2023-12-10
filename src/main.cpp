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
===============================================================================*/

//main.cpp

#include <iostream>
#include "EnvVar.hpp"
#include "ConfigManager.hpp"
#include "Logger.hpp"
#include "ArgumentConfig.hpp"
#include "Arguments.hpp"
#include "CommandLineProcessor.hpp"
#include "UiManager.hpp"

//=============================================================================
/* @brief Main entrance point of the program.
 * @param[in] argc The count of arguments provided
 * @param[in] argv A list of char* of arguments
 * @return An integer that denotes the endstate of the program to the OS
 * @since 1.0.0
 * @version 1.1
 * @author Henrik Sørensen
 * @date 2023-01-01
 * @todo Further Development
 */
//=============================================================================
int main(int argc, char* argv[]) {
    //=========================================================================
    // Initialization
    //=========================================================================
    try {
        // Define and process command-line arguments
        auto definedArgs = ArgumentConfig::getDefinedArguments();
        Arguments cmdArgs(argc, argv, definedArgs);
        CommandLineProcessor cmdProcessor(cmdArgs);
        ArgumentConfig::setupArguments(cmdProcessor);
        cmdProcessor.Process();

        // Initialize configuration manager
        ConfigManager configManager("config.json", cmdArgs);

        // Initialize environment variables
        EnvVarUtils myVar("LOGPATH");
        std::string logPathValue = myVar.get();
        Logger::getInstance().log("LOGPATH value: " + logPathValue, "main", Logger::Severity::Info);

        // Create and run the UI
        UIManager uiManager(configManager, cmdArgs);
        uiManager.run();

    } catch (const std::exception& e) {
        std::cerr << "Error During Initialization: " << e.what() << std::endl;
        exit(1);
    }

    //=========================================================================
    // Cleanup code
    //=========================================================================
    // Any necessary cleanup before exiting

    return 0;
}