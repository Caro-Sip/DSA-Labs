#include <iostream>

int main() {
    int n1 = 7;
    int n2 = 3;
    int n3 = 15;

    int* p1 = &n1;
    int* p2 = &n2;
    int* p3 = &n3;

    std::cout << "p1: " << p1 << "\n";
    std::cout << "n1: " << *p1 << "\n";

    std::cout << "p2: " << p2 << "\n";
    std::cout << "n2: " << *p2 << "\n";

    std::cout << "p3: " << p3 << "\n";
    std::cout << "n3: " << *p3 << "\n";

    *p3 = n1 + n2;

    std::cout << "p3: " << p3 << "\n";
    std::cout << "n3: " << *p3 << "\n";

    return 0;
}