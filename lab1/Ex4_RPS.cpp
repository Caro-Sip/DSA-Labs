#include <iostream>
#include <ctime>
#include <cmath>
#include <unistd.h>


void printHand(int hand){
    if (hand == 0){
        std::cout << "rock";
    }
    else if (hand == 1){
        std::cout << "paper";
    }
    else if (hand == 2){
        std::cout << "scissor";
    }
    else{
        std::cout << "error";
    }
    std::cout << std::endl;
    return;
}

int8_t isWin(uint8_t p, uint8_t b){
    if (p == b){
        return 0;
    }
    else if (p > b || (p == 0 && b == 2)){
        return 1;
    }
    else if (p < b || (p == 2 && b == 0)){
        return -1;
    }

}

int main(){
    while(true){
        srand(time(0));
        uint8_t botAnswer = rand()% 3;
        int pAnswer = 0;

        std::cout << "[0] rock\n";
        std::cout << "[1] paper\n";
        std::cout << "[2] scissor\n";
        std::cout << "[3] Exit Game\n";

        std::cout << "Choose a hand: ";
        std::cin >> pAnswer;
        std::cin.ignore(1000, '\n');
        if (std::cin.fail()) {
            std::cin.clear();
            continue;  // Skip round
        }

        if (pAnswer == 3) break;

        std::cout << "You chose: ";
        printHand(pAnswer);

        std::cout << "The Bot chose: ";
        sleep(1); //second
        printHand(botAnswer);

        int8_t result = isWin(pAnswer, botAnswer);
        if (result == 1) {
            std::cout << "Chipi-chipi, chapa-chapa!" << std::endl;
        }
        else if (result == -1) {
            std::cout << "Whomp Whomp, so sad!" << std::endl;
        }
        else {
            std::cout << "Next Game!" << std::endl;
        }
        std::cout << std::endl;
        sleep(1);
    }

    return 0;
}