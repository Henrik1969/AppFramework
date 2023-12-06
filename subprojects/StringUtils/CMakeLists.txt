# Define the StringUtils library

add_library(StringUtils
    StringUtils.cpp
)

# Set include directories for TimeUtils library
target_include_directories(StringUtils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
