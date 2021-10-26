# Set cmake_mimimum_required
# ----------------------------------
cmake_minimum_required(VERSION 3.20.0)

# Set project name and version
# ----------------------------------
project(Iridescent VERSION 0.1.0 LANGUAGES C CXX)

# Add subdirectories
# ----------------------------------
add_subdirectory(Core)

# Create executable
# ----------------------------------
add_executable(${PROJECT_NAME} main.cpp)

# Set target link libraries
# ----------------------------------
target_link_libraries(${PROJECT_NAME} Core)

