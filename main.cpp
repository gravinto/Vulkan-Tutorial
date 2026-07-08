#if defined(__INTELLISENSE__) || !defined(USE_CPP20_MODULES)

#include <vulkan/vulkan_raii.hpp>
#else
import vulkan_hpp;
#endif

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    GLFWwindow *window = nullptr;    

    void initWindow() {
        
        glfwInit();
        
        // Because GLFW was originally designed to create an OpenGL context, 
        // we need to tell it to not create an OpenGL context with a later call
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        // handling resized windows takes special care that we’ll look into later, 
        // disable it for now with another window hint call
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        // Initialize the window
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);


    }
    
    void initVulkan() {

    }

    void mainLoop() {
        // Keep the application running until an error occurs or the window is closed
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);

        glfwTerminate();
    }
};

int main()
{
    try
    {
        HelloTriangleApplication app;
        app.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}