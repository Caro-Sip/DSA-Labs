#include <iostream>
#include <ctime>

int main(){
    unsigned long minutes = 2038450921;

    unsigned int hours = (minutes / 60) % 24;
    double remainderMinutes = minutes % 60;
    unsigned int seconds = 0;

    std::cout << hours << ":" << remainderMinutes << ":" << seconds << std::endl;
    return 0;
}