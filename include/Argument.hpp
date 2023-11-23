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
#include <sstream>
#include <stdexcept>

enum class E_Argument_ValueType {
    None,
    Integer,
    Float,
    String,
    // Add more types as needed
};

// Define a struct to hold all argument data (if you are using this approach)
struct ArgumentData {
    std::string longName;
    std::string shortName;
    std::string description;
    bool needValue;
    E_Argument_ValueType valueType;
    std::string defaultValue;
    bool hasDefaultValue;
};

class Argument {
public:
    Argument(const std::string& longname, const std::string& shortname,
             const std::string& description, bool needValue, 
             E_Argument_ValueType valueType);

    // Constructor that takes ArgumentData struct
    Argument(const ArgumentData& data);

    std::string getLongName() const;
    std::string getShortName() const;
    std::string getDescription() const;
    bool needsValue() const;
    E_Argument_ValueType getValueType() const;

    void setValue(const std::string& value);
    void setDefaultValue(const std::string& defaultValue);
    std::string getDefaultValue() const;
    bool hasDefaultValue() const;

    //CHANGED: Moved the template function definition to the header file
    template <typename T>
    T getValue() const;

private:
    std::string longName;
    std::string shortName;
    std::string description;
    bool needValue;
    E_Argument_ValueType valueType;
    std::string value; // Store the value as a string

    // New members for default value handling
    std::string defaultValue;
    bool hasDefaultValueFlag = false;
};

#endif // ARGUMENT_HPP


