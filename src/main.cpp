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

#include <iostream>
#include "EnvVar.hpp"
#include "ConfigManager.hpp"
#include "Logger.hpp"
#include "ArgumentConfig.hpp"
#include "Argument.hpp"
#include "Arguments.hpp"
#include "CommandLineProcessor.hpp"

//=============================================================================
/* @brief Main enterancepoint of the program.
 * @param[in] argc The count of arguments provided
 * @param[in] argv A list of char* of arguments
 * @return An integer that denotes the endstate of the program to the OS
 * @since 1.0.0
 * @version 1.1
 * @author Henrik Sørensen <henriksorensen1969@gmail.com>
 * @date 2023-01-01
 * @todo Further Development
*/
//=============================================================================
int main(int argc, char* argv[]) {
	//=========================================================================
	// Initalization 
	//=========================================================================
    try {
        auto definedArgs = ArgumentConfig::getDefinedArguments();
        Arguments cmdArgs(argc, argv, definedArgs);
        CommandLineProcessor cmdProcessor(cmdArgs);
        ArgumentConfig::setupArguments(cmdProcessor);
        cmdProcessor.Process();
        EnvVarUtils myVar("LOGPATH");
        std::string logPathValue = myVar.get();
        Logger::getInstance().log("LOGPATH value: " + logPathValue, "main", Logger::Severity::Info);
        ConfigManager configManager("config.json", cmdArgs);
    } catch (const std::exception& e) {
        std::cerr << "Error During Initialization: " << e.what() << std::endl;
        exit(1);
    }
    //=========================================================================
    // Do the actual work here 
    //=========================================================================


	//=========================================================================
    // Cleanup code
    //=========================================================================

    //§ TODO

    return 0;
}