#include <iostream>

int main() {
    [[maybe_unused]] double pi{3.14};
    int width{5};

    // std:cout -- character output
    std::cout << "The width is " << width << std::endl;

    // std::endl -- end line;

    std::cout << "Hi!" << std::endl;
    std::cout << "I'm Govind";

    std::cout << "Enter two numbers: ";

    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    std::cout << "You entered " << x << " and " << y << '\n';

    return 0;

    return 0;
}
