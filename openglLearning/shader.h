/// This file is the specification of Shader
/// by Shizumu on 2022-7-8
/// version 1.0

#ifndef OPENGLLEARNING_SHADER_H
#define OPENGLLEARNING_SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
private:
    unsigned int ID; // the program id
public:
    Shader(const char * vertexPath, const char * fragmentPath);

    void use() const; // use or active the shader
    unsigned int program() const;

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};


#endif //OPENGLLEARNING_SHADER_H
