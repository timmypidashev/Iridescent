# Set cmake_mimimum_required
# ----------------------------------
cmake_minimum_required(VERSION 3.20.0)

# Set project name and version
# ----------------------------------
project(Iridescent VERSION 0.1.0 LANGUAGES C CXX)

# Configure Header Files
# --------------------------------------------------------------
configure_file(config.h.in config.h)

# --- Add Path For Local Cmake Scripts ---
# --------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Cmake")

# Local Cmake Scripts Used
# ----------------------------------
include(CMake/GetPlatform.cmake)

# Add subdirectories
# ----------------------------------
add_subdirectory(Core)

# Create executable
# ----------------------------------
add_executable(${PROJECT_NAME} main.cpp)

# Set target link libraries
# ----------------------------------
target_link_libraries(${PROJECT_NAME} Core)

