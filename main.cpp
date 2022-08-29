#include <iostream>
#include <thread>
#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct Vector3
{
    float x,y,z;
};

int main(int argc, char *argv[]){
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;
    glfwInit();
    glewInit();
    GLFWwindow* window = glfwCreateWindow(640, 480, "test", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}