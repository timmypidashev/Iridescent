# Set cmake_mimimum_required
# ----------------------------------
cmake_minimum_required(VERSION 3.21.2)

# Set project name
# ----------------------------------
project(Core LANGUAGES C CXX)

# Set Library name
# ----------------------------------
set(LIBRARY_NAME "Core")

# Set library sources
# ----------------------------------
set(SOURCE_FILES
    Iridescent.cpp
    Iridescent.h
)

# Add library sources
# ----------------------------------
add_library(
    ${LIBRARY_NAME} SHARED ${SOURCE_FILES}
)

# Expose source files to client application
# ----------------------------------
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# List files that install and/or package should provide.
# Each library should know what it want to distribute,
# which files are internal or intermediate and which are public library export.
# ----------------------------------
install(
    TARGETS Core 
    DESTINATION Core-bin
)
install(
    FILES Iridescent.h 
    DESTINATION Core-include
)
