# Set project name
# ----------------------------------
project(Sandbox)

# Create executable
# ----------------------------------
add_executable(${PROJECT_NAME} main.cpp)

# Set target link libraries
# ----------------------------------
target_link_libraries(${PROJECT_NAME} PUBLIC
    Core
)


