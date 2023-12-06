cmake_minimum_required(VERSION 3.0)
project(UiManager)

# Find the GTK package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Define the UiManager library
add_library(UiManager
    UiManager.cpp
)

# Include GTK headers
target_include_directories(UiManager
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    	${GTK3_INCLUDE_DIRS}
    	${CMAKE_CURRENT_SOURCE_DIR}/../CommandLineProcessor
)

# Link GTK libraries
target_link_libraries(UiManager
    ${GTK3_LIBRARIES}
)

# Additional GTK flags
target_compile_options(UiManager
    PUBLIC ${GTK3_CFLAGS_OTHER}
)
