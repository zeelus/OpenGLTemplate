#define GLFW_INCLUDE_NONE
#include <stdlib.h>
#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>
#include <glbinding/CallbackMask.h>
#include <GLFW/glfw3.h>


#include "source/Rendering.h"

const gl::GLint WIDTH = 800, HEIGHT = 600;

int main() {

    if(!glfwInit()) {
        printf("GLFW init failt\n");
        glfwTerminate();
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test window", NULL, NULL);

    if(!mainWindow) {
        printf("Window create fail!\n");
        return 1;
    }

    int widthBufferSize, heightBufferSize;

    glfwGetFramebufferSize(mainWindow, &widthBufferSize, &heightBufferSize);

    glfwMakeContextCurrent(mainWindow);

    glbinding::initialize(glfwGetProcAddress);

    gl::glViewport(0, 0, widthBufferSize, heightBufferSize);

    Rendering rendering;

    rendering.init();


    while (!glfwWindowShouldClose(mainWindow)) {

        glfwPollEvents();

        gl::glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT);

        rendering.draw();

        glfwSwapBuffers(mainWindow);

    }

    return 0;
}