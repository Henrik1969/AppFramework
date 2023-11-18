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

#include "Arguments.hpp"
#include <stdexcept>

Arguments::Arguments(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        Args.push_back(std::string(argv[i]));
    }
}

int Arguments::getNumArgs() const {
    return Args.size();
}

std::string Arguments::getArg(int index) const {
    if (index < 0 || index >= Args.size()) {
        throw std::out_of_range("Index is out of bounds");
    }
    return Args[index];
}

bool Arguments::isInArgs(const std::string& str) const {
    for (const auto& arg : Args) {
        if (arg == str) {
            return true;
        }
    }
    return false;
}
