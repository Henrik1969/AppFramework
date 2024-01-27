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

//StringUtils.cpp

#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <string>

namespace StringUtils {

	class StringRange {
	public:
	    int from_char;
	    int to_char;
	
	    StringRange(int from, int to);
		StringRange(const StringRange& other);
	};

    void replaceAll(std::string& str, const std::string& from, const std::string& to);

    //------------------------------------------------------------------------------------------------------------------
	// Case Conversion Functions:
	//------------------------------------------------------------------------------------------------------------------
    //Convert all characters in the string to lowercase.
    void toLower(std::string& str); 								
    void toLower(std::string& str, int from_char,int to_char);
    std::string toLowerCopy(const std::string& str);
    std::string toLowerCopy(const std::string& str, int from_char, int to_char);
    void toLower(std::string& str, const StringRange& range);
    std::string toLowerCopy(const std::string& str, const StringRange& range);
 	//------------------------------------------------------------------------------------------------------------------
    //Convert all characters in the string to uppercase.
    void toUpper(std::string& str); 					
    void toUpper(std::string& str, int from_char,int to_char);
    std::string toUpperCopy(const std::string& str);
    std::string toUpperCopy(const std::string& str, int from_char, int to_char);
    void toUpper(std::string& str, const StringRange& range);
    std::string toUpperCopy(const std::string& str, const StringRange& range);
 	//------------------------------------------------------------------------------------------------------------------
    //Swiches case of all characters in the string.
    void swichCase(std::string& str); 							
    void swichCase(std::string& str, int from_char,int to_char);
    std::string switchCaseCopy(const std::string& str);
    std::string switchCaseCopy(const std::string& str, int from_char, int to_char);
    void switchCase(std::string& str, const StringRange& range);
    std::string switchCaseCopy(const std::string& str, const StringRange& range);
 	//------------------------------------------------------------------------------------------------------------------
    void toTitleCase(std::string& str);
    void toTitleCase(std::string& str, int from_char,int to_char);
    std::string toTitleCaseCopy(const std::string& str);
    std::string toTitleCaseCopy(const std::string& str, int from_char, int to_char);
    void toTitleCase(std::string& str, const StringRange& range);
    std::string toTitleCaseCopy(const std::string& str, const StringRange& range);
 	//------------------------------------------------------------------------------------------------------------------
    void toSentenceCase(std::string& str);
    void toSentenceCase(std::string& str, int from_char,int to_char);
    std::string toSentenceCaseCopy(const std::string& str);
    std::string toSentenceCaseCopy(const std::string& str, int from_char, int to_char);
    void toSentenceCase(std::string& str, const StringRange& range);
    std::string toSentenceCaseCopy(const std::string& str, const StringRange& range);
 	//------------------------------------------------------------------------------------------------------------------
    void toCamelCase(std::string& str);
    void toCamelCase(std::string& str, int from_char,int to_char);
    std::string toCamelCaseCopy(const std::string& str);
    std::string toCamelCaseCopy(const std::string& str, int from_char, int to_char);
    void toCamelCase(std::string& str, const StringRange& range);
    std::string toCamelCaseCopy(const std::string& str, const StringRange& range);
 	//------------------------------------------------------------------------------------------------------------------
    void toSnakeCase(std::string& str);
    void toSnakeCase(std::string& str, int from_char,int to_char);
    std::string toSnakeCaseCopy(const std::string& str);
    std::string toSnakeCaseCopy(const std::string& str, int from_char, int to_char);
    void toSnakeCase(std::string& str, const StringRange& range);
    std::string toSnakeCaseCopy(const std::string& str, const StringRange& range);
 	//------------------------------------------------------------------------------------------------------------------
    void toAlternatingCase(std::string& str);
    void toAlternatingCase(std::string& str, int from_char,int to_char);
    std::string toAlternatingCaseCopy(const std::string& str);
    std::string toAlternatingCaseCopy(const std::string& str, int from_char, int to_char);
    void toAlternatingCase(std::string& str, const StringRange& range);
    std::string toAlternatingCaseCopy(const std::string& str, const StringRange& range);
 	//------------------------------------------------------------------------------------------------------------------
    //switches case of characters based on temp ex. "xxXXxXxxxXXXXxxXXX"
    void toCaseByTemplate(std::string& str,std::string& temp); 
	void toCaseByTemplate(std::string& str,std::string& temp, int from_char,int to_char);
    std::string toCaseByTemplateCopy(const std::string& str, const std::string& temp);
    std::string toCaseByTemplateCopy(const std::string& str, const std::string& temp, int from_char, int to_char);
    void toCaseByTemplate(std::string& str, const std::string& temp, const StringRange& range);
    std::string toCaseByTemplateCopy(const std::string& str, const std::string& temp, const StringRange& range);

} // namespace StringUtils

#endif // STRINGUTILS_HPP
