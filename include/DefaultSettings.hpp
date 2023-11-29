#ifndef DEFAULTSETTINGS_HPP
#define DEFAULTSETTINGS_HPP

#include <nlohmann/json.hpp>

class DefaultSettings {
public:
    static const nlohmann::json getDefaultConfig();

private:
    static const nlohmann::json defaultConfig;
};

#endif // DEFAULTSETTINGS_HPP
