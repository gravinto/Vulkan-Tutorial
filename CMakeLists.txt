cmake_minimum_required(VERSION 3.28)
project(VulkanTutorial LANGUAGES CXX)

option(ENABLE_CPP20_MODULE "Build the Vulkan-Hpp C++20 module target" OFF)

find_package (Vulkan REQUIRED)
find_package (glm REQUIRED)
find_package (glfw3 3.4 REQUIRED)

# set up Vulkan C++ module (enabled when ENABLE_CPP20_MODULE=ON)
add_library(VulkanCppModule)
add_library(Vulkan::cppm ALIAS VulkanCppModule)

target_compile_definitions(VulkanCppModule PUBLIC
        VULKAN_HPP_DISPATCH_LOADER_DYNAMIC=1
        VULKAN_HPP_NO_STRUCT_CONSTRUCTORS=1
)

target_include_directories(VulkanCppModule PRIVATE "${Vulkan_INCLUDE_DIR}")

target_link_libraries(VulkanCppModule PUBLIC Vulkan::Vulkan)

set_target_properties(VulkanCppModule PROPERTIES CXX_STANDARD 20)

target_sources(VulkanCppModule
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES
        BASE_DIRS "${Vulkan_INCLUDE_DIR}"
        FILES "${Vulkan_INCLUDE_DIR}/vulkan/vulkan.cppm"
)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries (${PROJECT_NAME} PRIVATE Vulkan::cppm)
target_link_libraries (${PROJECT_NAME} PRIVATE glm::glm)
target_link_libraries (${PROJECT_NAME} PRIVATE glfw)