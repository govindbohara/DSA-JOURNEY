#include <iostream>

int getValueFromUser() {
    std::cout << "Enter a integer: \n";
    int num{};

    std::cin >> num;

    return num;
}

int main() {
    int num{getValueFromUser()};
    std::cout << num << " doubled is: " << num * 2 << '\n';

    return 0;
}
