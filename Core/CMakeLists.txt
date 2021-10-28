# Set project name
# ----------------------------------
project(Core)

# Set library sources
# ----------------------------------
set(SOURCE_FILES
    Iridescent.cpp
    Iridescent.h
    Exports.h
)

# Add library sources
# ----------------------------------
add_library(
    ${PROJECT_NAME} SHARED ${SOURCE_FILES}
)

# Expose source files to client application
# ----------------------------------
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
