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

//CommandLineProcessor.hpp

#ifndef COMMANDLINEPROCESSOR_HPP
#define COMMANDLINEPROCESSOR_HPP

#include <functional>
#include <map>
#include <string>
#include <memory>
#include "Argument.hpp"
#include "Arguments.hpp"

using ArgumentHandler = std::function<void(const std::shared_ptr<Argument>&)>;

struct ArgumentHandlerPair {
    std::shared_ptr<Argument> arg;
    ArgumentHandler handler;

    ArgumentHandlerPair(std::shared_ptr<Argument> arg, const ArgumentHandler& handler)
        : arg(std::move(arg)), handler(handler) {}

    ArgumentHandlerPair() = default;
};

class CommandLineProcessor {
public:
    explicit CommandLineProcessor(const Arguments& args);

    void AddArgumentHandler(const Argument& arg, ArgumentHandler handler);
    void Process();

private:
    const Arguments& args;
    std::map<std::string, ArgumentHandlerPair> handlers;
};

#endif // COMMANDLINEPROCESSOR_HPP
