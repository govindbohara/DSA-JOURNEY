#include <iostream>

#include "summary.h"

int readNumber() {
    std::cout << "Enter a number to add: \n";

    int num{};

    std::cin >> num;

    return num;
}

void writeAnswer(int num) { std::cout << "The number you chose is: " << num << "\n"; }
