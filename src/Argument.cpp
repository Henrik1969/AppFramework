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

Argument::Argument(const ArgumentData& data):
longName(data.longName), 
shortName(data.shortName), 
description(data.description),
needValue(data.needValue), 
valueType(data.valueType), 
defaultValue(data.defaultValue),
hasDefaultValueFlag(data.hasDefaultValue){}

std::string Argument::getLongName() const	{return longName;}
std::string Argument::getShortName() const 	{return shortName;}
std::string Argument::getDescription() const {return description;}
bool Argument::needsValue() const {return needValue;}

E_Argument_ValueType Argument::getValueType() const {
    return valueType;
}

void Argument::setValue(const std::string& value) {
    this->value = value;
}

void Argument::setDefaultValue(const std::string& defaultValue) {
    this->defaultValue = defaultValue;
    this->hasDefaultValueFlag = true;
}

std::string Argument::getDefaultValue() const {
    return defaultValue;
}

bool Argument::hasDefaultValue() const {
    return hasDefaultValueFlag;
}

//CHANGED: Moved the template function definition to the header file
template <typename T>
T Argument::getValue() const {
    // Check if a value has been set for this argument
    if (value.empty()) {
        // If no value has been set and a default value is available, return it
        if (hasDefaultValueFlag) {
            std::istringstream defaultValueStream(defaultValue);
            T defaultValueValue;
            defaultValueStream >> defaultValueValue;
            return defaultValueValue;
        } else {
            // If no value or default value is available, throw an exception or return a suitable default value
            throw std::logic_error("No value set for this argument.");
        }
    }

    // Convert the stored string value to the requested type based on valueType
    std::istringstream valueStream(value);
    T typedValue;

    // Use try-catch for error handling during conversion
    try {
        valueStream >> typedValue;
    } catch (const std::exception& e) {
        // Conversion failed; throw an exception or handle the error accordingly
        throw std::invalid_argument("Error converting argument value to the requested type.");
    }

    if (valueStream.fail() || !valueStream.eof()) {
        // Conversion failed or there is extra data in the string
        throw std::invalid_argument("Invalid argument value.");
    }

    return typedValue;
}
// Instantiate the template function for specific types you use in Argument.cpp
template std::string Argument::getValue<std::string>() const;
template int Argument::getValue<int>() const;
template float Argument::getValue<float>() const;