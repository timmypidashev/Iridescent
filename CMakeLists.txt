# Set cmake_mimimum_required
# ----------------------------------
cmake_minimum_required(VERSION 3.21.2)

# Set project name and version
# ----------------------------------
project(Iridescent VERSION 0.1.0 LANGUAGES C CXX)

# Configure Header Files
# ----------------------------------
configure_file(config.h.in config.h)

# Allow 'config.h' to be used throughout the program
# ----------------------------------
include_directories(${PROJECT_BINARY_BIN})

# Run Cmake scripts
# ----------------------------------
include(CMake/GetPlatform.cmake)

# Add subdirectories
# ----------------------------------
add_subdirectory(Core)
add_subdirectory(Sandbox)

# USE_FOLDERS group cmake generated projects into one (CMakePredefinedTargets) folder
# ----------------------------------
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add CPack installer which brings all files together (.exe, .lib, .dll, and .h) and put into one file 
# ----------------------------------
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR ${Iridescent_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${Iridescent_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${Iridescent_VERSION_PATCH})
include(CPack)
