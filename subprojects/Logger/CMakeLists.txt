# Define the Logger library
add_library(Logger
    Logger.cpp
)

# Link Logger with TimeUtils and StringUtils
target_link_libraries(Logger
    PRIVATE
    	StringUtils
    	TimeUtils
    	EnvVar
)

# Set include directories for Logger library
target_include_directories(Logger
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

