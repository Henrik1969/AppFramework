#include "StringUtils.hpp"

namespace StringUtils {

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

    // Implementations of other utility functions

} // namespace StringUtils
