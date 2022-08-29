#include <iostream>
#include <thread>
#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct Vector3
{
    float x,y,z;
};


void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(int argc, char *argv[]){
    // Initialize GLFW
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;
    glfwInit();

    //die if GLFW fails to initialize
    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    // Set error callback
    glfwSetErrorCallback(error_callback);
    // Create a GLFWwindow object (a new window)
    GLFWwindow* window = glfwCreateWindow(640, 480, "test", nullptr, nullptr);
    // Check if the window could not be created
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }



    //set the current context to the newly created window
    glfwMakeContextCurrent(window);
    int width, height;
    // Get the width and height of the framebuffer to properly resize the window
    glfwGetFramebufferSize(window, &width, &height);
    // set glViewport to the size of the window
    glViewport(0, 0, width, height);

    if(glewInit()) {
        std::cout << glewGetErrorString(glewInit()) << std::endl;
        exit(EXIT_FAILURE);
    }

    //loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(window);

    }

    //terminate GLFW, clearing any resources allocated by GLFW.
    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
