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

#include "Argument.hpp"

Argument::Argument(const std::string& longname, const std::string& shortname,
                   const std::string& description, bool needValue,
                   E_Argument_ValueType valueType) 
    : longName(longname), shortName(shortname), description(description),
      needValue(needValue), valueType(valueType) {}

std::string Argument::getLongName() const {
    return longName;
}

std::string Argument::getShortName() const {
    return shortName;
}

std::string Argument::getDescription() const {
    return description;
}

bool Argument::needsValue() const {
    return needValue;
}

E_Argument_ValueType Argument::getValueType() const {
    return valueType;
}
