#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
    glfwInit();

    GLFWwindow* window =
        glfwCreateWindow(1280, 720, "Engine", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}