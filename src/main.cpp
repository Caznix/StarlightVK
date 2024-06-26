#include "first_app.hpp"
#include <exception>

#include <cstdlib>
#include <iostream>

int main() {
    starlight::FirstApp app{};

    try{
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}