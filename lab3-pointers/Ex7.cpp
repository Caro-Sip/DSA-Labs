#include <iostream>

void sum1(double *sum, int n);

int main(){
    double result = 0;

    sum1(&result, 5);
    std::cout << result << std::endl;
}

void sum1(double *sum, int n){
    int den;
    for(int i = 1; i <= n; i++){
        den = (n*10) + 2;
        *sum += 1.0/den;
    }
    return;
}