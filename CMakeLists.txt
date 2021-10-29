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

set(IRIDESCENT ${PROJECT_NAME})

# Configure cmake
# ----------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set options
# ----------------------------------
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(BUILD_EXAMPLES "Build examples" OFF)

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

# CMake modules
# ----------------------------------
# Standard modules
include(GenerateExportHeader)

# Own modules
include(GetPlatform)

# Ensure cmake can find our libraries
# ----------------------------------
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

# Add subdirectories
# ----------------------------------
add_subdirectory(External)
add_subdirectory(Core)
add_subdirectory(Sandbox)

# Nice message to calm me down when compiling :)
# ----------------------------------
message(STATUS "Configuring ${PROJECT_NAME} v${PROJECT_VERSION} for ${CMAKE_SYSTEM_NAME}")

