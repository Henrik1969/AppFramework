# Define the EnvVar library

add_library(EnvVar
    EnvVar.cpp
)

# Set include directories for EnvVar library
target_include_directories(EnvVar
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)