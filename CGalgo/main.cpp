#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    GLFWwindow * windows = glfwCreateWindow(800, 600, "CGalgo", nullptr, nullptr);
    if(windows == nullptr){
        std::cout << "Fail to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(windows);



    return 0;
}
