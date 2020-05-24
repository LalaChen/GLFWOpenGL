#include <iostream>

#include "glfwOGLInterface.h"

int main(int argc, char **argv)
{
    std::cout << "Main" << std::endl;
    Initialize();
    RunMainLoop();
    Terminate();
}