#include <iostream>

int getHeight() {
    int x{0};
    std::cout << "Enter the height of the tower in meters:";
    std::cin >> x;
    return x;
}

int main() {
    const double g{9.8};
    int height{getHeight()};
    for (size_t i = 0; i <= 5; i++) {
        double distanceFallen = g * ((i * i) / 2.0);
        double distanceLeft = static_cast<int>(height) - distanceFallen;
        if (distanceLeft < 0) {
            std::cout << "At 5 seconds, the ball is on the ground.\n";
            break;
        };
        std::cout << "At " << i << " seconds, the ball is at height: " << distanceLeft
                  << " metres\n";
    }
    return 0;
}
