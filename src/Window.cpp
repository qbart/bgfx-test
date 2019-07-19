#include "Window.hpp"
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3.h>
#if BX_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#include <GLFW/glfw3native.h>

namespace ee {

Window::Window()
{
}

Window::~Window()
{
    bgfx::shutdown();
    glfwTerminate();
}

bool Window::init(int w, int h, const char *title)
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(w, h, title, nullptr, nullptr);
    if (!window)
        return false;

    // Call bgfx::renderFrame before bgfx::init to signal to bgfx not to create a render thread.
    // Most graphics APIs must be used on the same thread that created the window.
    bgfx::renderFrame();

    // Initialize bgfx using the native window handle and window resolution.
    bgfx::Init init;
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
    init.platformData.ndt = glfwGetX11Display();
    init.platformData.nwh = (void *)(uintptr_t)glfwGetX11Window(window);
#elif BX_PLATFORM_OSX
    init.platformData.nwh = glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
    init.platformData.nwh = glfwGetWin32Window(window);
#endif

    glfwGetWindowSize(window, &width, &height);
    init.resolution.width = (uint32_t)width;
    init.resolution.height = (uint32_t)height;
    init.resolution.reset = BGFX_RESET_VSYNC;
    if (!bgfx::init(init))
        return false;

    return true;
}

void Window::maximize()
{
    glfwMaximizeWindow(window);
}

bool Window::wasResized()
{
    int oldWidth = width, oldHeight = height;
    glfwGetWindowSize(window, &width, &height);

    return (width != oldWidth || height != oldHeight);
}

bool Window::isOpen() const
{
    return !glfwWindowShouldClose(window);
}

void Window::close()
{
    glfwSetWindowShouldClose(window, true);
}

int Window::getKey(int key) const
{
    return glfwGetKey(window, key);
}

void Window::setKeyCallback(GLFWkeyfun fn)
{
	glfwSetKeyCallback(window, fn);
}

}
