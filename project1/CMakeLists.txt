cmake_minimum_required(VERSION 3.10)
project(OpenGLProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# Specify the source files
set(SOURCES
    src/main.cpp
    src/Shader.cpp
)

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})

# Create executable
add_executable(OpenGLProject ${SOURCES})

# Link libraries
target_link_libraries(OpenGLProject ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)

# Copy shader files to build directory
configure_file(src/default.vs default.vs COPYONLY)
configure_file(src/default.frag default.frag COPYONLY)
configure_file(src/container.jpg container.jpg COPYONLY)


# Include stb_image.h from src directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)