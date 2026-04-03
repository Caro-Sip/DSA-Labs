#include <iostream>

int main() {
    int n = 0;
    int* p = &n;

    std::cout << "input a number n: ";
    std::cin >> *p;

    *p += 7;

    std::cout << "Value of n is now: " << *p << "\n";

    return 0;
}