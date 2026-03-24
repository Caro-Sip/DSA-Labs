#include <iostream>

int sumOdd(int n){
    // base case 
    if (n <= 0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }
    if (n % 2 != 0) {
        return n + sumOdd(n - 1);
    }
    else {
        return sumOdd(n - 1);
    }
}

int main(){
    int n = 0;

    std::cout << "Input a number for summing the odds from then: ";
    std::cin >> n;

    std::cout << "Sum of odd from " << n << " is " << sumOdd(n);
    return 0;
}