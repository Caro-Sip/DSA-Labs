#include <iostream>

void exchange(int* a, int* b);

int main(){
    int a = 7;
    int b = 6;

    int* pa = &a;
    int* pb = &b;

    std::cout << "a is : " << *pa << "\n";
    std::cout << "b is : " << *pb << "\n";

    exchange(pa, pb);

    std::cout << "a is now : " << *pa << "\n";
    std::cout << "b is now : " << *pb << "\n";
    return 0;
}

void exchange(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}