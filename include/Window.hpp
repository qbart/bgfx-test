#pragma once

#include <GLFW/glfw3.h>

namespace ee {

class Window
{
  public:
    Window();
    ~Window();

    bool init(int w, int h, const char *title);
    void maximize();
    bool wasResized();
    bool isOpen() const;
    void close();
    int getKey(int key) const;
    void setKeyCallback(GLFWkeyfun fn);

    uint32_t getWidth() const { return (uint32_t)width; }
    uint32_t getHeight() const { return (uint32_t)height; }

  private:
    GLFWwindow *window = nullptr;
    int width;
    int height;
};

}
