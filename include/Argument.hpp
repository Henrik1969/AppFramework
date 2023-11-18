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

#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP

#include <string>

enum class E_Argument_ValueType {
    None,
    Integer,
    Float,
    String,
    // Add more types as needed
};

class Argument {
public:
    Argument(const std::string& longname, const std::string& shortname,
             const std::string& description, bool needValue, 
             E_Argument_ValueType valueType);

    std::string getLongName() const;
    std::string getShortName() const;
    std::string getDescription() const;
    bool needsValue() const;
    E_Argument_ValueType getValueType() const;

private:
    std::string longName;
    std::string shortName;
    std::string description;
    bool needValue;
    E_Argument_ValueType valueType;
};

#endif // ARGUMENT_HPP
