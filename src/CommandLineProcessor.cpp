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
#include "CommandLineProcessor.hpp"

CommandLineProcessor::CommandLineProcessor(const Arguments& args) : args(args) {}

void CommandLineProcessor::AddArgumentHandler(const Argument& arg, ArgumentHandler handler) {
    auto argPtr = std::make_shared<Argument>(arg);
    handlers[arg.getLongName()] = ArgumentHandlerPair(argPtr, handler);
    std::cout << "Handler added for long name: " << arg.getLongName() << std::endl;

    if (!arg.getShortName().empty()) {
        handlers[arg.getShortName()] = ArgumentHandlerPair(argPtr, handler);
        std::cout << "Handler added for short name: " << arg.getShortName() << std::endl;
    }
}

void CommandLineProcessor::Process() {
    for (const auto& argPair : args.getArgValues()) {
        std::string argName = argPair.first;
        std::cout << "Processing argument: " << argName << std::endl;

        auto it = handlers.find(argName);
        if (it != handlers.end()) {
        	std::cout << "Handler found for: " << argName << std::endl;
            // Update the value of the argument before calling the handler
            it->second.arg->setValue(argPair.second);
            it->second.handler(it->second.arg);
        }else{
        	std::cout << "No handler found for: " << argName << std::endl;
        }
    }
}