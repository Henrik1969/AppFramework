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

#include "CommandLineProcessor.hpp"

CommandLineProcessor::CommandLineProcessor(const Arguments& args) : args(args) {}

void CommandLineProcessor::AddArgumentHandler(const Argument& arg, ArgumentHandler handler) {
    auto argPtr = std::make_shared<Argument>(arg);
    handlers[arg.getLongName()] = ArgumentHandlerPair(argPtr, handler);

    // Map the short name to the same handler, if it's provided
    if (!arg.getShortName().empty()) {
        handlers[arg.getShortName()] = ArgumentHandlerPair(argPtr, handler);
    }
}

void CommandLineProcessor::Process() {
    for (int i = 0; i < args.getNumArgs(); ++i) {
        std::string argStr = args.getArg(i);
        auto it = handlers.find(argStr);
        if (it != handlers.end()) {
            it->second.handler(it->second.arg);
        }
    }
}