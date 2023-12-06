cmake_minimum_required(VERSION 3.10)

# Define the CommandLineProcessor library
add_library(CommandLineProcessor
    ArgumentConfig.cpp
    Argument.cpp
    Arguments.cpp
    CommandLineProcessor.cpp
    ConfigManager.cpp
    DefaultSettings.cpp
)

# Set include directories for CommandLineProcessor library
target_include_directories(CommandLineProcessor
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link CommandLineProcessor with other subproject dependencies (if any)
target_link_libraries(CommandLineProcessor
    PRIVATE
        Logger
        StringUtils
        TimeUtils
        EnvVar
    # Add any other dependencies as needed
)
