# Define the StringUtils library

add_library(StringUtils
    StringUtils.cpp
)

# Set include directories for TimeUtils library
target_include_directories(StringUtils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# You can also specify any additional dependencies for TimeUtils if needed
# For example, if TimeUtils depends on some other libraries, link them here

# Example:
# target_link_libraries(TimeUtils
#     PRIVATE SomeOtherLibrary
# )

# Optionally, set compiler flags, compile definitions, etc., specific to TimeUtils
# target_compile_options(TimeUtils
#     PRIVATE -some_flag
# )

# Optionally, enable C++ features for TimeUtils
# target_compile_features(TimeUtils
#     PRIVATE cxx_std_17
# )