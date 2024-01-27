/*
  This file is part of the AppEssential project.

  AppEssential is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, GPL version 4.

  AppEssential is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License version 4 for more details.

  You should have received a copy of the GNU General Public License
  along with AppEssential. If not, see <https://www.gnu.org/licenses/>.
*/

// StringUtils.hpp

#include "StringUtils.hpp"
#include <string>
#include <algorithm>
#include <cctype> // For std::toupper, std::tolower
#include <stdexcept> 

namespace StringUtils {
	
	StringRange::StringRange(int from, int to) : from_char(from), to_char(to) {
        if (from_char < 0 || to_char < 0 || from_char > to_char) {
            throw std::invalid_argument("Invalid range: from_char must be less than or equal to to_char and non-negative");
        }
    }

	StringRange::StringRange(const StringRange& other) : from_char(other.from_char), to_char(other.to_char){};

    void replaceAll(std::string& str, const std::string& from, const std::string& to) {
        if (from.empty()) {
            return;
        }
        size_t startPos = 0;
        while ((startPos = str.find(from, startPos)) != std::string::npos) {
            str.replace(startPos, from.length(), to);
            startPos += to.length();
        }
    }
//=============================================================================================
// Case conversions
//=============================================================================================
    
//---------------------------------------------------------------------------------------------
//	toLower
//---------------------------------------------------------------------------------------------
    
    void toLower(std::string& str) {
        for (auto& ch : str) {
            ch = std::tolower(static_cast<unsigned char>(ch));
        }
    }

    void toLower(std::string& str, int from_char, int to_char) {
	    if (from_char < 0 || to_char >= str.size()) {
	        throw std::out_of_range("Index out of range");
	    }
	    if (from_char > to_char) {
	        throw std::invalid_argument("Invalid range: from_char is greater than to_char");
	    }
	
	    for (int i = from_char; i <= to_char; ++i) {
	        str[i] = std::tolower(static_cast<unsigned char>(str[i]));
	    }
	}
    
    void toLower(std::string& str, const StringRange& range) {
        if (range.to_char >= str.size()) {
            throw std::out_of_range("Range exceeds string length");
        }
        for (int i = range.from_char; i <= range.to_char; ++i) {
            str[i] = std::tolower(static_cast<unsigned char>(str[i]));
        }
    }
	
	std::string toLowerCopy(const std::string& str) {
	    std::string result = str;
	    toLower(result);
	    return result;
	}
    
    std::string toLowerCopy(const std::string& str, const StringRange& range) {
        std::string result = str;
        toLower(result, range);
        return result;
    }
	
	std::string toLowerCopy(const std::string& str, int from_char, int to_char) {
        if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
            throw std::out_of_range("Invalid range specified");
        }
        std::string result = str;
        for (int i = from_char; i <= to_char; ++i) {
            result[i] = std::tolower(static_cast<unsigned char>(result[i]));
        }
        return result;
    }

//---------------------------------------------------------------------------------------------
//	toUpper
//---------------------------------------------------------------------------------------------
    
    void toUpper(std::string& str) {
        for (auto& ch : str) {
            ch = std::toupper(static_cast<unsigned char>(ch));
        }
    }
	
	void toUpper(std::string& str, int from_char, int to_char) {
        if (from_char < 0 || from_char >= str.size()) {
            throw std::out_of_range("from_char index out of range");
        }
        if (to_char >= str.size()) {
            throw std::out_of_range("to_char index out of range");
        }
        if (from_char > to_char) {
            throw std::invalid_argument("Invalid range: from_char is greater than to_char");
        }

        for (int i = from_char; i <= to_char; ++i) {
            str[i] = std::toupper(static_cast<unsigned char>(str[i]));
        }
    }
	
	std::string toUpperCopy(const std::string& str) {
	    std::string result = str;
	    toUpper(result);
	    return result;
	}
    
    void toUpper(std::string& str, const StringRange& range) {
        if (range.to_char >= str.size()) {
            throw std::out_of_range("Range exceeds string length");
        }
        for (int i = range.from_char; i <= range.to_char; ++i) {
            str[i] = std::toupper(static_cast<unsigned char>(str[i]));
        }
    }
    
    std::string toUpperCopy(const std::string& str, const StringRange& range) {
        std::string result = str;
        toUpper(result, range);
        return result;
    }
    
    std::string toUpperCopy(const std::string& str, int from_char, int to_char) {
        if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
            throw std::out_of_range("Invalid range specified");
        }
        std::string result = str;
        for (int i = from_char; i <= to_char; ++i) {
            result[i] = std::toupper(static_cast<unsigned char>(result[i]));
        }
        return result;
    }

//---------------------------------------------------------------------------------------------
//	switchCase
//---------------------------------------------------------------------------------------------
    
    void switchCase(std::string& str) {
        for (auto& ch : str) {
            if (std::islower(static_cast<unsigned char>(ch))) {
                ch = std::toupper(static_cast<unsigned char>(ch));
            } else if (std::isupper(static_cast<unsigned char>(ch))) {
                ch = std::tolower(static_cast<unsigned char>(ch));
            }
        }
    }
    
    void switchCase(std::string& str, int from_char, int to_char) {
        if (from_char < 0 || from_char >= str.size()) {
            throw std::out_of_range("from_char index out of range");
        }
        if (to_char >= str.size()) {
            throw std::out_of_range("to_char index out of range");
        }
        if (from_char > to_char) {
            throw std::invalid_argument("Invalid range: from_char is greater than to_char");
        }

        for (int i = from_char; i <= to_char; ++i) {
            if (std::islower(static_cast<unsigned char>(str[i]))) {
                str[i] = std::toupper(static_cast<unsigned char>(str[i]));
            } else if (std::isupper(static_cast<unsigned char>(str[i]))) {
                str[i] = std::tolower(static_cast<unsigned char>(str[i]));
            }
        }
    }
    
    void switchCase(std::string& str, const StringRange& range) {
        if (range.to_char >= str.size()) {
            throw std::out_of_range("Range exceeds string length");
        }
        for (int i = range.from_char; i <= range.to_char; ++i) {
            if (std::islower(static_cast<unsigned char>(str[i]))) {
                str[i] = std::toupper(static_cast<unsigned char>(str[i]));
            } else if (std::isupper(static_cast<unsigned char>(str[i]))) {
                str[i] = std::tolower(static_cast<unsigned char>(str[i]));
            }
        }
    }
    
    std::string switchCaseCopy(const std::string& str, const StringRange& range) {
        std::string result = str;
        switchCase(result, range);
        return result;
    }
	
	std::string switchCaseCopy(const std::string& str) {
	    std::string result = str;
	    switchCase(result);
	    return result;
	}
    
    std::string switchCaseCopy(const std::string& str, int from_char, int to_char) {
        if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
            throw std::out_of_range("Invalid range specified");
        }
        std::string result = str;
        for (int i = from_char; i <= to_char; ++i) {
            if (std::islower(static_cast<unsigned char>(result[i]))) {
                result[i] = std::toupper(static_cast<unsigned char>(result[i]));
            } else if (std::isupper(static_cast<unsigned char>(result[i]))) {
                result[i] = std::tolower(static_cast<unsigned char>(result[i]));
            }
        }
        return result;
    }

//---------------------------------------------------------------------------------------------
//	toTitleCase
//---------------------------------------------------------------------------------------------
    
    void toTitleCase(std::string& str) {
        bool capitalizeNext = true;
        for (char& ch : str) {
            ch = capitalizeNext ? std::toupper(ch) : std::tolower(ch);
            capitalizeNext = std::isspace(static_cast<unsigned char>(ch));
        }
    }
	
	void toTitleCase(std::string& str, int from_char, int to_char) {
	    if (from_char < 0 || from_char >= str.size() || to_char >= str.size() || from_char > to_char) {
	        throw std::out_of_range("Invalid range specified");
	    }
	
	    bool capitalizeNext = from_char == 0 || std::isspace(static_cast<unsigned char>(str[from_char - 1]));
	    for (int i = from_char; i <= to_char; ++i) {
	        str[i] = capitalizeNext ? std::toupper(str[i]) : std::tolower(str[i]);
	        capitalizeNext = std::isspace(static_cast<unsigned char>(str[i]));
	    }
	}
    
    std::string toTitleCaseCopy(const std::string& str, int from_char, int to_char) {
        if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
            throw std::out_of_range("Invalid range specified");
        }
        std::string result = str;
        bool capitalizeNext = true;
        for (int i = from_char; i <= to_char; ++i) {
            result[i] = capitalizeNext ? std::toupper(result[i]) : std::tolower(result[i]);
            capitalizeNext = std::isspace(static_cast<unsigned char>(result[i]));
        }
        return result;
    }
	
	std::string toTitleCaseCopy(const std::string& str) {
	    std::string result = str;
	    toTitleCase(result);
	    return result;
	}

	void toTitleCase(std::string& str, const StringRange& range) {
	    if (range.from_char >= str.size() || range.to_char >= str.size()) {
	        throw std::out_of_range("Range exceeds string bounds");
	    }
	
	    bool capitalizeNext = range.from_char == 0 || std::isspace(static_cast<unsigned char>(str[range.from_char - 1]));
	    for (int i = range.from_char; i <= range.to_char; ++i) {
	        str[i] = capitalizeNext ? std::toupper(str[i]) : std::tolower(str[i]);
	        capitalizeNext = std::isspace(static_cast<unsigned char>(str[i]));
	    }
	}
	
	// Function to return a modified copy of the string
	std::string toTitleCaseCopy(const std::string& str, const StringRange& range) {
	    if (range.from_char >= str.size() || range.to_char >= str.size()) {
	        throw std::out_of_range("Range exceeds string bounds");
	    }
	
	    std::string result = str;
	    bool capitalizeNext = range.from_char == 0 || std::isspace(static_cast<unsigned char>(str[range.from_char - 1]));
	    for (int i = range.from_char; i <= range.to_char; ++i) {
	        result[i] = capitalizeNext ? std::toupper(result[i]) : std::tolower(result[i]);
	        capitalizeNext = std::isspace(static_cast<unsigned char>(result[i]));
	    }
	    return result;
	}
//---------------------------------------------------------------------------------------------
//	toSentenceCase
//---------------------------------------------------------------------------------------------
    
    void toSentenceCase(std::string& str) {
        bool firstCharacter = true;
        for (char& ch : str) {
            ch = firstCharacter ? std::toupper(ch) : std::tolower(ch);
            firstCharacter = false;
        }
    }
	
	void toSentenceCase(std::string& str, int from_char, int to_char) {
	    if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
	        throw std::out_of_range("Invalid range specified");
	    }
	    for (int i = from_char; i <= to_char; ++i) {
	        str[i] = (i == from_char) ? std::toupper(str[i]) : std::tolower(str[i]);
	    }
	}

    //std::string toSentenceCaseCopy(const std::string& str);
    
    std::string toSentenceCaseCopy(const std::string& str, int from_char, int to_char) {
        if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
            throw std::out_of_range("Invalid range specified");
        }
        std::string result = str;
        for (int i = from_char; i <= to_char; ++i) {
            result[i] = (i == from_char) ? std::toupper(result[i]) : std::tolower(result[i]);
        }
        return result;
    }
//todo
/*
	void toSentenceCase(std::string& str, const StringRange& range);
    std::string toSentenceCaseCopy(const std::string& str, const StringRange& range);
*/
//---------------------------------------------------------------------------------------------
//	toCamelCase
//---------------------------------------------------------------------------------------------
    
    void toCamelCase(std::string& str) {
        bool capitalizeNext = false;
        std::string result;
        for (char ch : str) {
            if (std::isspace(static_cast<unsigned char>(ch))) {
                capitalizeNext = true;
            } else {
                result += capitalizeNext ? std::toupper(ch) : std::tolower(ch);
                capitalizeNext = false;
            }
        }
        str = result;
    }

	void toCamelCase(std::string& str, int from_char, int to_char) {
	    if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
	        throw std::out_of_range("Invalid range specified");
	    }
	    bool capitalizeNext = false;
	    std::string result;
	    for (int i = from_char; i <= to_char; ++i) {
	        if (std::isspace(static_cast<unsigned char>(str[i]))) {
	            capitalizeNext = true;
	        } else {
	            result += capitalizeNext ? std::toupper(str[i]) : std::tolower(str[i]);
	            capitalizeNext = false;
	        }
	    }
	    str.replace(from_char, to_char - from_char + 1, result);
	}
    
    std::string toCamelCaseCopy(const std::string& str, int from_char, int to_char) {
        if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
            throw std::out_of_range("Invalid range specified");
        }
        bool capitalizeNext = false;
        std::string result;
        for (int i = from_char; i <= to_char; ++i) {
            if (std::isspace(static_cast<unsigned char>(str[i]))) {
                capitalizeNext = true;
            } else {
                result += capitalizeNext ? std::toupper(str[i]) : std::tolower(str[i]);
                capitalizeNext = false;
            }
        }
        return result;
    }
	
	std::string toCamelCaseCopy(const std::string& str) {
	    std::string result = str;
	    toCamelCase(result);
	    return result;
	}
//todo
/*
	void toCamelCase(std::string& str, const StringRange& range);
    std::string toCamelCaseCopy(const std::string& str, const StringRange& range);
*/
//---------------------------------------------------------------------------------------------
//	toSnakeCase
//---------------------------------------------------------------------------------------------
    
    void toSnakeCase(std::string& str) {
        for (char& ch : str) {
            if (std::isspace(static_cast<unsigned char>(ch))) {
                ch = '_';
            } else {
                ch = std::tolower(ch);
            }
        }
    }
	
	void toSnakeCase(std::string& str, int from_char, int to_char) {
	    if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
	        throw std::out_of_range("Invalid range specified");
	    }
	    for (int i = from_char; i <= to_char; ++i) {
	        if (std::isspace(static_cast<unsigned char>(str[i]))) {
	            str[i] = '_';
	        } else {
	            str[i] = std::tolower(str[i]);
	        }
	    }
	}

    std::string toSnakeCaseCopy(const std::string& str, int from_char, int to_char) {
        if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
            throw std::out_of_range("Invalid range specified");
        }
        std::string result = str;
        for (int i = from_char; i <= to_char; ++i) {
            if (std::isspace(static_cast<unsigned char>(result[i]))) {
                result[i] = '_';
            } else {
                result[i] = std::tolower(static_cast<unsigned char>(result[i]));
            }
        }
        return result;
    }

	std::string toSnakeCaseCopy(const std::string& str) {
	    std::string result = str;
	    toSnakeCase(result);
	    return result;
	}
//todo
/*
	void toSnakeCase(std::string& str, const StringRange& range);
    std::string toSnakeCaseCopy(const std::string& str, const StringRange& range);
*/
//---------------------------------------------------------------------------------------------
//	toAlternatingCase
//---------------------------------------------------------------------------------------------
    
    void toAlternatingCase(std::string& str) {
        bool lowercase = true;
        for (char& ch : str) {
            ch = lowercase ? std::tolower(ch) : std::toupper(ch);
            lowercase = !lowercase;
        }
    }
    
    void toAlternatingCase(std::string& str, int from_char, int to_char) {
	    if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
	        throw std::out_of_range("Invalid range specified");
	    }
	    bool lowercase = true;
	    for (int i = from_char; i <= to_char; ++i) {
	        str[i] = lowercase ? std::tolower(str[i]) : std::toupper(str[i]);
	        lowercase = !lowercase;
	    }
	}

    std::string toAlternatingCaseCopy(const std::string& str, int from_char, int to_char) {
        if (from_char < 0 || to_char >= str.size() || from_char > to_char) {
            throw std::out_of_range("Invalid range specified");
        }
        std::string result = str;
        bool lowercase = true;
        for (int i = from_char; i <= to_char; ++i) {
            result[i] = lowercase ? std::tolower(static_cast<unsigned char>(result[i])) : std::toupper(static_cast<unsigned char>(result[i]));
            lowercase = !lowercase;
        }
        return result;
    }

	std::string toAlternatingCaseCopy(const std::string& str) {
	    std::string result = str;
	    toAlternatingCase(result);
	    return result;
	}
//todo
/*
	void toAlternatingCase(std::string& str, const StringRange& range);
    std::string toAlternatingCaseCopy(const std::string& str, const StringRange& range);
*/
//---------------------------------------------------------------------------------------------
//	toCaseByTemplate
//---------------------------------------------------------------------------------------------
    
    void toCaseByTemplate(std::string& str, const std::string& temp) {
        if (temp.size() < str.size()) {
            throw std::invalid_argument("Template string is shorter than the input string");
        }

        for (size_t i = 0; i < str.size(); ++i) {
            if (std::isupper(static_cast<unsigned char>(temp[i]))) {
                str[i] = std::toupper(static_cast<unsigned char>(str[i]));
            } else {
                str[i] = std::tolower(static_cast<unsigned char>(str[i]));
            }
        }
    }
	
	void toCaseByTemplate(std::string& str, const std::string& temp, int from_char, int to_char) {
	    if (from_char < 0 || to_char >= str.size() || from_char > to_char ||
	        to_char >= temp.size()) {
	        throw std::out_of_range("Invalid range or template string is too short");
	    }
	
	    for (int i = from_char; i <= to_char; ++i) {
	        if (std::isupper(temp[i])) {
	            str[i] = std::toupper(str[i]);
	        } else {
	            str[i] = std::tolower(str[i]);
	        }
	    }
	}

	std::string toCaseByTemplateCopy(const std::string& str, const std::string& temp) {
	    std::string result = str;
	    toCaseByTemplate(result, temp);
	    return result;
	}
//todo
/*
	std::string toAlternatingCaseCopy(const std::string& str, int from_char, int to_char);
    void toCaseByTemplate(std::string& str, const std::string& temp, const StringRange& range);
    std::string toCaseByTemplateCopy(const std::string& str, const std::string& temp, const StringRange& range);
*/
//=============================================================================================
// Trimming Functions
//=============================================================================================
// In-place trimming of whitespace from both ends of the string
void trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

// Returns a new string with whitespace trimmed from both ends
std::string trim(const std::string& str) {
    std::string trimmed = str;
    trim(trimmed);
    return trimmed;
}

// In-place trimming of whitespace from the left (beginning) of the string
void ltrim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// Returns a new string with whitespace trimmed from the left (beginning)
std::string ltrim(const std::string& str) {
    std::string trimmed = str;
    ltrim(trimmed);
    return trimmed;
}

// In-place trimming of whitespace from the right (end) of the string
void rtrim(std::string& str) {
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

// Returns a new string with whitespace trimmed from the right (end)
std::string rtrim(const std::string& str) {
    std::string trimmed = str;
    rtrim(trimmed);
    return trimmed;
}
//=============================================================================================
// Splitting and Joining Functions
//=============================================================================================
/*
       split(const std::string& str, char delimiter): Split the string into a vector of strings based on a delimiter.
       join(const std::vector<std::string>& strings, const std::string& delimiter): Join elements of a vector of strings into a single string with a given delimiter.
//=============================================================================================
// String Searching Functions
//=============================================================================================
        contains(const std::string& str, const std::string& substr): Check if str contains substr.
        startsWith(const std::string& str, const std::string& prefix): Check if str starts with prefix.
        endsWith(const std::string& str, const std::string& suffix): Check if str ends with suffix.
//=============================================================================================
// Numeric Conversion Functions
//=============================================================================================
        toInt(const std::string& str): Convert a string to an integer.
        toFloat(const std::string& str): Convert a string to a float.
        toString(int num): Convert an integer to a string.
        toString(float num): Convert a float to a string.
//=============================================================================================
// String Formatting Functions
//=============================================================================================    
        format(const std::string& format, ...): Implement a printf-like function for string formatting.
//=============================================================================================
// Regular Expression Functions
//=============================================================================================
        regexMatch(const std::string& str, const std::string& pattern): Check if a string matches a regular expression.
        regexSearch(const std::string& str, const std::string& pattern): Search within a string for a regular expression pattern.
        regexReplace(std::string& str, const std::string& pattern, const std::string& replaceWith): Replace parts of a string based on a regular expression pattern.
//=============================================================================================
// Encoding and Decoding Functions
//=============================================================================================    
        urlEncode(const std::string& str): Encode a string for safe URL transmission.
        urlDecode(const std::string& str): Decode a URL-encoded string.
        base64Encode(const std::string& str): Encode a string in base64.
        base64Decode(const std::string& str): Decode a base64 encoded string.
//=============================================================================================
// Character and Substring Replacement Functions
//=============================================================================================    
        replaceAllChars(std::string& str, char from, char to): Replace all occurrences of a character with another character.
        removeChars(std::string& str, char charToRemove): Remove all occurrences of a specific character.
//=============================================================================================
// Utility Functions
//=============================================================================================    
        reverse(std::string& str): Reverse the string.
        isPalindrome(const std::string& str): Check if the string is a palindrome.
*/
	
	
	
	
	


} // namespace StringUtils
