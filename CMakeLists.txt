cmake_minimum_required(VERSION 3.10)
project(testing VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(include)

option(THREAD_SAFE "Enable thread safety" OFF)
if(THREAD_SAFE)
    add_compile_definitions(THREAD_SAFE)
endif()

# Find the nlohmann/json package
find_package(nlohmann_json REQUIRED)

# List of source files
set(SOURCES 
    src/ConfigManager.cpp
    src/EnvVar.cpp
    src/Logger.cpp
    src/Arguments.cpp
    src/Argument.cpp
	src/CommandLineProcessor.cpp
    src/main.cpp
    src/testair.cpp
    src/ArgumentConfig.cpp
#INSERTCLASSPOINT
)

add_executable(testing ${SOURCES})

# Link the JSON library
target_link_libraries(testing PRIVATE nlohmann_json::nlohmann_json)
