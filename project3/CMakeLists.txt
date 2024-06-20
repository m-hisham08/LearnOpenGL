cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(SampleProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# Add the executable
add_executable(SampleProject src/main.cpp src/Shader.cpp)

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} include include/stb)

# Link libraries
target_link_libraries(SampleProject ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)

# Copy shaders to the output directory
configure_file(shaders/vertex_shader.vert vertex_shader.vert COPYONLY)
configure_file(shaders/fragment_shader.frag fragment_shader.frag COPYONLY)
configure_file(resources/container.jpg container.jpg COPYONLY)



