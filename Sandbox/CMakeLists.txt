# Set cmake_mimimum_required
# ----------------------------------
cmake_minimum_required(VERSION 3.21.2)

# Set project name and version
# ----------------------------------
project(Sandbox LANGUAGES C CXX)

# Create executable
# ----------------------------------
add_executable(${PROJECT_NAME} main.cpp)

# Set target link libraries
# ----------------------------------
target_link_libraries(${PROJECT_NAME} 
    Core
)

# Point to which directory Sandbox is copied during installation and packaging
# ----------------------------------
install(TARGETS Sandbox DESTINATION sandbox)