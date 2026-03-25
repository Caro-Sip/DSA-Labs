#include <iostream>

int sumNumbers();

int main(){
    std::cout << "Enter numbers (enter -1 to stop):\n";
    int total = sumNumbers();
    std::cout << "Total = " << total << "\n";
    return 0;
}

int sumNumbers(){
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;
    
    if(num == -1){
        return 0;
    }
    else {
        return num + sumNumbers();
    }
}
