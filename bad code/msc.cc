#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
 Shader(const char* vertexSource, const char* fragmentSource, const char* geometryPath = nullptr)
 {
 //load the vertex shader data
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexSource,NULL);
    //compile the vertex shader
    glCompileShader(vertexShader);

    //load the fragment shader data
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentSource,NULL);
    //compile the fragment shader
    glCompileShader(fragmentShader);
}
}