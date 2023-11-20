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

    void setValue(const std::string& value);

    template<typename T>
    T getValue() const {
        std::istringstream iss(value);
        T convertedValue;

        switch(valueType) {
            case E_Argument_ValueType::Integer:
                iss >> convertedValue;
                break;
            case E_Argument_ValueType::Float:
                iss >> convertedValue;
                break;
            case E_Argument_ValueType::String:
                return value;
            // Handle other types as needed
            default:
                throw std::invalid_argument("Unsupported value type");
        }

        if (iss.fail()) {
            throw std::runtime_error("Value conversion failed");
        }

        return convertedValue;
    }

private:
    std::string longName;
    std::string shortName;
    std::string description;
    bool needValue;
    E_Argument_ValueType valueType;
    std::string value; // Store the value as a string
};

#endif // ARGUMENT_HPP
