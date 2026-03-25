#include <iostream>

void printMenu();
int power(int m, int n);
int sumSquare(int n);
int sumDigit(int n);

int main(){
    int input = 0;

    do {
        printMenu();

        std::cout << "Choice: ";
        std::cin >> input;

        switch(input){
            case 1: {
                int m = 0;
                int n = 0;

                std::cout << "Format: m^n\n";
                std::cout << "Input base m: ";
                std::cin >> m;
                std::cout << "Input power: ";
                std::cin >> n;

                std::cout << "The power of " << m << "^" << n << " is " << power(m, n) << "\n";
                break;
            }
            case 2: {
                int n = 0;
                
                std::cout << "Summing the squared natural number to n\n";
                std::cout << "Input n: ";
                std::cin >> n;

                std::cout << "The sum of squares to n is " << sumSquare(n) << "\n";
                break;
            }
            case 3: {
                int n = 0;
                std::cout << "Summing the individual digit values of a number n\n";
                std::cout << "Input multi-digit number: ";
                std::cin >> n;

                std::cout << "The sum of number's digit: " << sumDigit(n) << "\n";
                break;
            }
            default:
                std::cout << "Invalid Argument Reinitializing\n";
        }
    } while (input != 0);
}

void printMenu(){
    std::cout << "1 power \n";
    std::cout << "2 sum of square\n";
    std::cout << "3 sum of digits\n";
    std::cout << "0 Exit\n";
    return;
}

int power(int m, int n){
    if (n == 0){
        return 1;
    }
    else if (n == 1){
        return m;
    }
    else {
        return m * power(m, n-1);
    }
}

int sumSquare(int n){
    if(n <= 1){
        return 1;
    }
    else {
        return (n*n) + sumSquare(n-1);
    }
}

int sumDigit(int n){
    if (n < 10) {
        return n;
    }
    else {
        return (n % 10) + sumDigit(n / 10);
    }
}