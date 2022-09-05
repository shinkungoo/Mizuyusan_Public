/// This file is the implementation of Shader
/// by Shizumu on 2022-7-8
/// version 1.0

#include "shader.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath) {
    /// 1. retrieve the vertex and fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read the contents of buffer of file into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file stream
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }catch (std::ifstream::failure & error){
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }
    const char * vShaderCode = vertexCode.c_str();
    const char * fShaderCode = fragmentCode.c_str();

    /// 2. Compile shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    // vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    // print vertex shader compile errors if any
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER:::VERTEX_COMPILATION_FAILED" << std::endl
        << infoLog << std::endl;
    }
    // fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    // print fragment shader compile errors if any
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER:::FRAGMENT_COMPILATION_FAILED" << std::endl
                  << infoLog << std::endl;
    }

    // shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    // print link errors if any
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER:::PROGRAM_LINKING_FAILED" << std::endl
                  << infoLog << std::endl;
    }
    // delete shaders because they're linked into our program and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::Shader(const char *shaderPath) {
    /// 1. retrieve the vertex and fragment source code from filePath
    std::string shaderCode;
    std::ifstream shaderFile;
    // ensure ifstream objects can throw exceptions:
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        // open files
        shaderFile.open(shaderPath);
        std::stringstream shaderStream;
        // read the contents of buffer of file into streams
        shaderStream << shaderFile.rdbuf();
        // close file stream
        shaderFile.close();
        // convert stream into string
       shaderCode = shaderStream.str();
    }catch (std::ifstream::failure & error){
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }
    const char * sShaderCode = shaderCode.c_str();

    /// 2. Compile shaders
    unsigned int shader;
    int success;
    char infoLog[512];

    // shader
    shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader, 1, &sShaderCode, nullptr);
    glCompileShader(shader);
    // print vertex shader compile errors if any
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER:::VERTEX_COMPILATION_FAILED" << std::endl
                  << infoLog << std::endl;
    }

    // shader program
    ID = glCreateProgram();
    glAttachShader(ID, shader);
    glLinkProgram(ID);
    // print link errors if any
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER:::PROGRAM_LINKING_FAILED" << std::endl
                  << infoLog << std::endl;
    }
    // delete shaders because they're linked into our program and no longer necessary
    glDeleteShader(shader);
}

void
Shader::use() const {
    glUseProgram(ID);
}

unsigned int
Shader::program() const {
    return ID;
}

void
Shader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), static_cast<int>(value));
}

void
Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void
Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}