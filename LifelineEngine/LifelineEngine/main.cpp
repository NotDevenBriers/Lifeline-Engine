#include <glad/glad.h>
#include <iostream>

#include "Window.h"
#include "Renderer.h"

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    auto* renderer = static_cast<Renderer*>(glfwGetWindowUserPointer(window));
    if (renderer)
    {
        renderer->Clear();
        glfwSwapBuffers(window);
    }
}

int main()
{
    Window window(1280, 720, "Lifeline Engine");

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return -1;

    glViewport(0, 0, 1280, 720);

    Renderer renderer;
    renderer.Init();
    renderer.SetClearColor(0.2f, 0.3f, 0.4f, 1.0f);

    glfwSetWindowUserPointer(window.GetNativeWindow(), &renderer);
    glfwSetFramebufferSizeCallback(window.GetNativeWindow(), FramebufferSizeCallback);

    while (!window.ShouldClose())
    {
        renderer.Clear();
        window.SwapBuffers();
        window.PollEvents();
    }

    return 0;
}