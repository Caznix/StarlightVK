#pragma once

#include <string>
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

namespace starlight {
    class StarlightWindow {
        public:
            StarlightWindow(int w, int h, std::string name);
            ~StarlightWindow();
        private:

            void initWindow();

            const int width;
            const int height;

            std::string windowName;
            GLFWwindow *window;
    };
}