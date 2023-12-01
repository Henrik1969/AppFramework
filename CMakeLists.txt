#
#  This file is part of the AppFramework project.
#
#  AppFramework is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, GPL version 4.
#
#  AppFramework is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License version 4 for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with AppFramework. If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.10)
project(testing VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_PARALLEL_LEVEL 20)

include_directories(include)

# Include subprojects
add_subdirectory(subprojects/TimeUtils)
add_subdirectory(subprojects/StringUtils)
add_subdirectory(subprojects/Logger)
add_subdirectory(subprojects/EnvVar)

option(THREAD_SAFE "Enable thread safety" OFF)
if(THREAD_SAFE)
    add_compile_definitions(THREAD_SAFE)
endif()

option(ENABLE_DEBUG "Enable debugging messages in output" ON)
if(ENABLE_DEBUG)
    add_compile_definitions(ENABLE_DEBUG)
endif()


# Find the nlohmann/json package

find_package(nlohmann_json REQUIRED)

# List of source files

set(SOURCES 
    src/ConfigManager.cpp
    src/Arguments.cpp
    src/Argument.cpp
	src/CommandLineProcessor.cpp
    src/main.cpp
    src/ArgumentConfig.cpp
    src/DefaultSettings.cpp

#INSERTCLASSPOINT
)

add_executable(main ${SOURCES})

# Link the executable with TimeUtils and StringUtils
target_link_libraries(main PRIVATE TimeUtils)
target_link_libraries(main PRIVATE StringUtils)
target_link_libraries(main PRIVATE Logger)
target_link_libraries(main PRIVATE EnvVar)

# Link the JSON library

target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)