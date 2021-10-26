# Set cmake_mimimum_required
# ----------------------------------
cmake_minimum_required(VERSION 3.20.0)

# Set project name
# ----------------------------------
project(Core)

# Set Library name
# ----------------------------------
set(LIBRARY_NAME "Core")

# Set library sources
# ----------------------------------
set(SOURCE_FILES
    Iridescent.cpp
    Iridescent.h
)

# cmake config
# ----------------------------------
set(BUILD_SHARED_LIBS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS True)


# Add library sources
# ----------------------------------
add_library(
    ${LIBRARY_NAME} SHARED ${SOURCE_FILES}
)

# Expose source files to client application
# ----------------------------------
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}
)