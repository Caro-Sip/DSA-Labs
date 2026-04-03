#include <iostream>
#include <math.h>

void solveEquation(int a, int b, int c, float *x1, float *x2, float *delta);

int main(){
    int a, b, c;
    float x1, x2, delta;
    
    do {
        std::cout << "========== Quadratic Equation Solver ==========" << std::endl;
        std::cout << "Solves equations of the form: ax² + bx + c = 0" << std::endl;
        std::cout << "=============================================\n" << std::endl;
        
        std::cout << "Enter coefficient a: ";
        std::cin >> a;
        if (a == 0) {
            std::cout << "Value of a must not be 0\n";
            continue;
        }
        
        std::cout << "Enter coefficient b: ";
        std::cin >> b;
        
        std::cout << "Enter coefficient c: ";
        std::cin >> c;
    } while(a==0); 

    solveEquation(a, b, c, &x1, &x2, &delta);

    if (delta >= 0){
        std::cout << "delta : " << delta << "\n";
        std::cout << "x1 : " << x1 << "\n";
        std::cout << "x2 : " << x2 << "\n";
    }
    
    return 0;
}

void solveEquation(int a, int b, int c, float *x1, float *x2, float *delta){
    *delta = (b*b) - (4*a*c);

    if (*delta < 0){
        std::cout << "The equation is complex like your heart\n";
        return;
    }
    else if (*delta == 0){
        *x1 = (-b)/(2*a);
        *x2 = *x1;
        return;
    }
    else if (*delta > 0){
        *x1 = (-b+sqrt(*delta))/(2*a);
        *x2 = (-b-sqrt(*delta))/(2*a);
        return;
    }
}