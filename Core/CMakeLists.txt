# Set project name
# ----------------------------------
project(Core)

# Set library sources
# ----------------------------------
set(SOURCE_FILES
    Application/Application.cpp
    Application/Application.h 
    Application/EntryPoint.h 
    Application/Exports.h
    Iridescent.h
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
