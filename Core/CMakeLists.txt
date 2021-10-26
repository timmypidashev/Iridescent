# Set cmake_mimimum_required
# ----------------------------------
cmake_minimum_required(VERSION 3.20.0)

# Set Library name
set(LIBRARY_NAME "Core")

# Set library sources
# ----------------------------------
set(SOURCE_FILES
    Iridescent.h
)

# Add library sources
# ----------------------------------
add_library(
    ${LIBRARY_NAME} SHARED ${SOURCE_FILES}
)
