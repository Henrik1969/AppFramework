# Define the TimeUtils library

add_library(TimeUtils
    TimeUtils.cpp
)

# Set include directories for TimeUtils library
target_include_directories(TimeUtils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
