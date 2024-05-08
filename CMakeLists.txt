cmake_minimum_required(VERSION 3.6)
project(StarlightVK VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)

add_subdirectory(./lib/glfw)
SET(GLM_TEST_ENABLE OFF CACHE BOOL "GLM Build unit tests")
add_subdirectory(./lib/glm      EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} Vulkan::Vulkan glm::glm)
#option(GLFW_USE_X11 "Use X11 for GLFW backend" ON)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)