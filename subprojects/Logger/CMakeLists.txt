# CMakeLists.txt for Logger subproject

# Define the Logger library
add_library(Logger
    Logger.cpp
    # ... other source files ...
)

# Link Logger with TimeUtils, StringUtils, and EnvVar
target_link_libraries(Logger
    PRIVATE
        StringUtils
        TimeUtils
        EnvVar
)

# Set include directories for Logger library
target_include_directories(Logger
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../CommandLineProcessor  # Include CommandLineProcessor subdirectory
)