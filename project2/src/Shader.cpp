#include "Shader.h"

Shader::Shader(const GLchar *vertexSourcePath, const GLchar *fragmentSourcePath)
{
    std::string vertexSourceCode, fragmentSourceCode;
    std::ifstream vertexSourceFile, fragmentSourceFile;
    vertexSourceFile.exceptions(std::ifstream::badbit);
    fragmentSourceFile.exceptions(std::ifstream::badbit);

    try
    {
        vertexSourceFile.open(vertexSourcePath);
        fragmentSourceFile.open(fragmentSourcePath);

        std::stringstream vertexFileStream, fragmentFileStream;

        vertexFileStream << vertexSourceFile.rdbuf();
        fragmentFileStream << fragmentSourceFile.rdbuf();

        vertexSourceFile.close();
        fragmentSourceFile.close();

        vertexSourceCode = vertexFileStream.str();
        fragmentSourceCode = fragmentFileStream.str();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    const GLchar *vShaderCode = vertexSourceCode.c_str();
    const GLchar *fShaderCode = fragmentSourceCode.c_str();

    GLuint fShader, vShader;
    vShader = glCreateShader(GL_VERTEX_SHADER);
    fShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vShader, 1, &vShaderCode, NULL);
    glShaderSource(fShader, 1, &fShaderCode, NULL);

    GLint success;
    GLchar infoLog[512];

    glCompileShader(vShader);

    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER.CPP::FAILED TO COMPILE VERTEX SHADER " << infoLog << std::endl;
    }

    glCompileShader(fShader);

    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER.CPP::FAILED TO COMPILE FRAGMENT SHADER " << infoLog << std::endl;
    }

    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, vShader);
    glAttachShader(this->shaderProgram, fShader);
    glLinkProgram(this->shaderProgram);

    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER.CPP::FAILED TO LINK SHADER PROGRAM " << infoLog << std::endl;
    }

    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::use()
{
    glUseProgram(this->shaderProgram);
}
