#include <iostream>

int main(){
    int n = 0;
    int sum = 0;

    do {
        std::cout << "Input a number (bigger than 50):";
        std::cin >> n;
        if(n <= 50) std::cout << "Yar! shimmer me timber, you no speak latin? lers 50 lah\n" << std::endl;
    } while(n <= 50);

    for(int i = 1; i <= n; i++){
        if (i == 10 || i == 30) continue;
        sum+=i;
    }

    std::cout << sum << std::endl; 
}