# Set project name
# ----------------------------------
project(Core)

# Set library sources
# ----------------------------------
set(SOURCE_FILES
    # Client header file
    Iridescent.h

    # Predefines
    Exports.h

    # Application sources
    Application/Application.cpp
    Application/Application.h 
    Application/EntryPoint.h 

    # Logger sources
    Logger/Log.cpp 
    Logger/Log.h
    
)

# Add library sources
# ----------------------------------
add_library(
    ${PROJECT_NAME} STATIC ${SOURCE_FILES}
)

# Add Precompiled Headers
# ----------------------------------
target_precompile_headers(${PROJECT_NAME} PRIVATE Iridpch.h)

# Set Library Includes
# ----------------------------------
target_include_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set target link libraries
# ----------------------------------
target_link_libraries(${PROJECT_NAME}
	PUBLIC spdlog::spdlog
)