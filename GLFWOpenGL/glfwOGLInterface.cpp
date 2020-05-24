#include <iostream>

#include <GL/glew.h>
#include <glfw/glfw3.h>

#include "glfwOGLInterface.h"

GLFWwindow *g_window = nullptr;
GLFWmonitor *g_monitor = nullptr;
uint32_t g_win_width = 1200u;
uint32_t g_win_height = 800u;

// ---- - Keyboard------
void KeyEventCallback(GLFWwindow *i_window, int i_key, int i_scancode, int i_action, int i_mod_keys)
{
    if (i_key == GLFW_KEY_ESCAPE && i_action == GLFW_PRESS) {
        glfwSetWindowShouldClose(i_window, GLFW_TRUE);
    }
}

//----- error return ------
void ErrorCallback(int i_error, const char *i_error_str)
{
}

//----- Mouse ------
void CursorMouseButtonCallback(GLFWwindow *i_window, int i_button, int i_action, int i_mod_keys)
{
}

void CursorEnterCallback(GLFWwindow *i_window, int entered)
{
    //Enter or leave
}

void CursorPositionCallback(GLFWwindow *i_window, double i_x, double i_y)
{
    //Motion
}

//----- JoyStick ------
void JoyStickCallback(int i_jid, int i_event)
{

}

//----- DropItem ------
void DropCallback(GLFWwindow *i_window, int i_count, const char** i_paths)
{

}

//----- Window ------
void WindowCloseCallback(GLFWwindow *i_window)
{

}

void WindowMaximizeCallback(GLFWwindow *i_window, int i_maximized)
{

}

void WindowPosCallback(GLFWwindow *i_window, int i_x, int i_y)
{

}

void WindowSizeCallback(GLFWwindow *i_window, int i_w, int i_h)
{
}

void WindowFocusCallback(GLFWwindow *i_window, int i_focused)
{

}

//----- monitor ------
void MonitorCallback(GLFWmonitor *i_monitor, int i_event)
{

}

void ScrollCallback(GLFWwindow *i_window, double i_x, double i_y)
{

}

void Initialize()
{
    glfwSetErrorCallback(ErrorCallback);
    if (glfwInit() == false) {
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);

    //full screen.
    //g_monitor = glfwGetPrimaryMonitor();
    //const GLFWvidmode *mode = glfwGetVideoMode(g_monitor);
    //glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    //glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    //glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    //glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    //g_win_width = mode->width; g_win_height = mode->height;

    g_window = glfwCreateWindow(g_win_width, g_win_height, "GLFW_OPENGL_TEST", g_monitor, NULL);
    
    if (g_window == nullptr) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    //5. register key cbk.
    //--- keyboard
    glfwSetKeyCallback(g_window, KeyEventCallback);
    //--- Mouse
    glfwSetCursorPosCallback(g_window, CursorPositionCallback);
    glfwSetMouseButtonCallback(g_window, CursorMouseButtonCallback);
    glfwSetCursorPosCallback(g_window, CursorPositionCallback);
    glfwSetCursorEnterCallback(g_window, CursorEnterCallback);
    //------ Windows
    glfwSetWindowCloseCallback(g_window, WindowCloseCallback);
    glfwSetWindowMaximizeCallback(g_window, WindowMaximizeCallback);
    glfwSetFramebufferSizeCallback(g_window, WindowSizeCallback);
    glfwSetWindowPosCallback(g_window, WindowPosCallback);
    glfwSetWindowFocusCallback(g_window, WindowFocusCallback);
    glfwSetDropCallback(g_window, DropCallback);
    glfwSetScrollCallback(g_window, ScrollCallback);
}

void RunMainLoop()
{
    glfwMakeContextCurrent(g_window);
    glewInit();

    std::cout << "GL_VERSION :" << glGetString(GL_VERSION) << std::endl;

    while (glfwWindowShouldClose(g_window) == false) {
        try {
            // Render scene.
            glClearColor(0.5f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        catch (std::exception &e) {
        }

        // Swap buffers
        glfwSwapBuffers(g_window);
        glfwPollEvents();
    }
}

void Terminate()
{
}