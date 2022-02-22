# Set project name
# ----------------------------------
project(Iridescent)

# Create executable
# ----------------------------------
add_executable(Iridescent main.cpp)

# Set target link libraries
# ----------------------------------
target_link_libraries(${PROJECT_NAME} 
    PRIVATE Core
)

