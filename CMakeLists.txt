cmake_minimum_required(VERSION 3.10)
project(VulkanTutorial)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(VulkanTutorial main.cpp)

target_link_libraries(VulkanTutorial PRIVATE Vulkan::Vulkan glfw glm::glm)