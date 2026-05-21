#pragma once

#include <GLFW/glfw3.h>
#include <string>

class Window
{
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool ShouldClose() const;

    void PollEvents();
    void SwapBuffers();

    int GetWidth() const;
    int GetHeight() const;

    GLFWwindow* GetNativeWindow() const;

private:
    GLFWwindow* m_Window;

    int m_Width;
    int m_Height;
    std::string m_Title;

private:
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};