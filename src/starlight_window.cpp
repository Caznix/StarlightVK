#include "starlight_window.hpp"
#include "GLFW/glfw3.h"
#include <string>
namespace starlight {
    StarlightWindow::StarlightWindow(int w,int h,std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }

    StarlightWindow::~StarlightWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void StarlightWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);

        window = glfwCreateWindow( width, height, windowName.c_str(), nullptr,nullptr);
    }
}