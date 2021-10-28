# Set cmake_mimimum_required
# ----------------------------------
cmake_minimum_required(VERSION 3.20.0)

# Set makefile properties
# ----------------------------------
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set C++ 17 Standard
# ----------------------------------
set(CMAKE_CXX_STANDARD 17)

# Set project name and version
# ----------------------------------
project(Iridescent VERSION 0.1.0 LANGUAGES C CXX)

# Nice message to calm me down when compiling :)
# ----------------------------------
message(STATUS "Configuring ${PROJECT_NAME}: v${PROJECT_VERSION}")

# Configure Header Files
# ----------------------------------
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

# Allow 'config.h' to be used throughout the program
# ----------------------------------
include_directories(${PROJECT_BINARY_DIR})

# Add compile definitions
# ----------------------------------
add_compile_definitions(IRID_EXPORTS)

# Run Cmake scripts
# ----------------------------------
include(CMake/GetPlatform.cmake)

# Ensure cmake can find our libraries
# ----------------------------------
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

# Add subdirectories
# ----------------------------------
add_subdirectory(Core)
add_subdirectory(Sandbox)



