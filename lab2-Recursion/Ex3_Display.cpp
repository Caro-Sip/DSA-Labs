#include <iostream>
#include <unistd.h>

void displayStar(int n) {
    if (n == 0) {
        std::cout << std::endl; 
        return;
    }
    if (n > 0) {
        std::cout << '*';
        return displayStar(n-1);
    }
}

void displayBox(int row, int col){
    if(row == 0){
        std::cout << std::endl;
        return;
    }
    if (row > 0){
        displayStar(col);
        displayBox(row - 1, col);
    }
}

void displayNumber(int n) {
    if (n == 1){
        std::cout << 1 << " \n";
        return;
    }
    if (n > 1){
        std::cout << n << " ";
        return displayNumber(n - 1);
    }
}

int main() {
    int input = 0;

    do{
        std::cout << "Choose the following functions:\n";
        std::cout << "[1] Display n stars\n";
        std::cout << "[2] Display n to 1\n";
        std::cout << "[3] DIsplay a box of stars\n";
        std::cout << "[0] Exit the Program\n";
        std::cout << "Choose: ";
        std::cin >> input;
        std::cout << std::endl;
        
        switch(input){
            case 1:
                std::cout << "choose a number of stars: ";
                std::cin >> input;
                displayStar(input);
                break;
            case 2:
                std::cout << "choose the n number: ";
                std::cin >> input;
                displayNumber(input);
                break;
            case 3:
                int row, col;
                std::cout << "Enter number of rows: ";
                std::cin >> row;
                std::cout << "Enter number of cols: ";
                std::cin >> col;
                displayBox(row,col);
                break;                ;
            case 0:
                std::cout << "Exiting program\n";
                sleep(2);
                break;
            default:
                std::cout << "Invalid input\n";
                break;
        }
        std::cout << std::endl;
    }while(input != 0);
}