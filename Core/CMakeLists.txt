# Set project name
# ----------------------------------
project(Core)

# Set compile definitions
# ----------------------------------
add_definitions("-pthread")

# Easily find required packages
# ----------------------------------
find_package (Threads REQUIRED)
find_package (OpenGL REQUIRED)

# Set library sources
# ----------------------------------
set(SOURCE_FILES
    # Application header
    Iridescent.h

    # Predefines
    Exports.h

    # Input
    Input/Input.h
    Input/KeyCodes.h
    Input/MouseButtonCodes.h

    # Application sources
    Application/Application.cpp
    Application/Application.h 
    Application/EntryPoint.h 

    # Logger sources
    Logger/Log.cpp 
    Logger/Log.h

    # Events sources
    Events/ApplicationEvents.h 
    Events/Event.h 
    Events/KeyEvent.h 
    Events/MouseEvent.h

    # Window
    Window/Windows.cpp
    Window/WindowsInput.cpp
    Window/WindowsInput.h
    Window/Windows.h
    Window.h

    # Layerstack
    Layer/Layer.cpp
    Layer/LayerStack.cpp
    Layer/Layer.h
    Layer/LayerStack.h

    # ImGui
    ImGui/ImGuiBuild.cpp
    ImGui/ImGuiLayer.cpp
    ImGui/ImGuiLayer.h

    # Renderer
    Renderer/Shader.cpp
    Renderer/Renderer.cpp
    Renderer/Buffer.cpp
    Renderer/VertexArray.cpp
    Renderer/VertexArray.h
    Renderer/Shader.h
    Renderer/GraphicsContext.h
    Renderer/Renderer.h
    Renderer/Buffer.h


    # Platform
    Platform/OpenGL/OpenGLContext.cpp
    Platform/OpenGL/OpenGLBuffer.cpp
    Platform/OpenGL/OpenGLVertexArray.cpp
    Platform/OpenGL/OpenGLVertexArray.h
    Platform/OpenGL/OpenGLContext.h
    Platform/OpenGL/OpenGLBuffer.h

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
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set target link libraries
# ----------------------------------
target_link_libraries(${PROJECT_NAME} PUBLIC 
	spdlog::spdlog
    glfw
    glad
    imgui
    glm
    ${OPENGL_LIBRARY}
)
