#pragma once

#include "starlight_window.hpp"

namespace starlight {
    class FirstApp{
        public:
            static constexpr int WIDTH = 1600;
            static constexpr int HEIGHT = 850;

        void run(){};
        private:
            StarlightWindow starlightWindow{WIDTH,HEIGHT,"StarlightVK is real!"};
    };
}