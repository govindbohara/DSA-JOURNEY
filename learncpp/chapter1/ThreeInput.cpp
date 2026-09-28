#include <iostream>

int main() {
    int x{};
    int y{};
    int z{};

    std::cout << "Enter three numbers:";

    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

    std::cout << "You entered " << x << "," << y << " and " << z << "\n";
    return 0;
}
