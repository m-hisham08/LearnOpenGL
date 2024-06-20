#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <GL/glew.h>

class Shader
{
public:
    GLuint shaderProgram;

    Shader(const GLchar *vertexSourcePath, const GLchar *fragmentSourcePath);

    void use();
};

#endif