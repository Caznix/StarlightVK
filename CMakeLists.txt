cmake_minimum_required(VERSION 3.12)
project(StarlightVK VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(GLFW_DIR ${CMAKE_SOURCE_DIR}/lib/glfw)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)
add_library()
file(GLOB starlightvk_src CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.hpp"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/main.cpp" EXCLUDE_FROM_ALL
)
add_subdirectory(./lib/glfw)
SET(GLM_TEST_ENABLE OFF CACHE BOOL "GLM Build unit tests")
add_subdirectory(./lib/glm      EXCLUDE_FROM_ALL)
add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp ${starlightvk_src} glfw ${GLFW_LIBRARIES} Vulkan::Vulkan glm::glm)
option(GLFW_USE_X11 "Use X11 for GLFW backend" ON)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)