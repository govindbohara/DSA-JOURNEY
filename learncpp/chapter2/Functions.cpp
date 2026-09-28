#include <iostream>

void doSomething() { std::cout << "do Something\n"; }

int main() {
    std::cout << "Starting main()\n";
    doSomething();
    doSomething();
    std::cout << "Ending main\n";
}
