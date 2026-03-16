#include <iostream>
#include <cmath>

// i) Convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// ii) Convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// iii) Find roots of quadratic equation ax2 + bx + c = 0
void quadraticRoots(double a, double b, double c) {
    if (a == 0) {
        std::cout << "Not a quadratic equation (a cannot be 0)" << std::endl;
        return;
    }
    
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "Two distinct roots:" << std::endl;
        std::cout << "Root 1: " << root1 << std::endl;
        std::cout << "Root 2: " << root2 << std::endl;
    }
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "One root (repeated): " << root << std::endl;
    }
    else {
        std::cout << "No real roots (imaginary roots exist)" << std::endl;
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        std::cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << std::endl;
        std::cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }
}

// iv) Calculate BMI and categorize
void calculateBMI(double weight, double height) {
    double bmi = weight / (height * height);
    
    std::cout << "BMI: " << bmi << std::endl;
    
    if (bmi < 18.5) {
        std::cout << "Category: Underweight" << std::endl;
    }
    else if (bmi < 25) {
        std::cout << "Category: Normal Weight" << std::endl;
    }
    else if (bmi < 30) {
        std::cout << "Category: Overweight" << std::endl;
    }
    else {
        std::cout << "Category: Obese" << std::endl;
    }
}

// v) Sum numbers from 1 to n except those divisible by 3
long long sumExceptDivisibleBy3(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 != 0) {
            sum += i;
        }
    }
    return sum;
}

// Menu function
void displayMenu() {
    std::cout << "\n===== Temperature & Math Calculator =====" << std::endl;
    std::cout << "1. Convert Celsius to Fahrenheit" << std::endl;
    std::cout << "2. Convert Fahrenheit to Celsius" << std::endl;
    std::cout << "3. Find Quadratic Equation Roots" << std::endl;
    std::cout << "4. Calculate BMI" << std::endl;
    std::cout << "5. Sum Numbers (1 to n, except divisible by 3)" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "========================================" << std::endl;
}

int main(){
    int choice;
    
    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        if (choice == 0) {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        
        switch (choice) {
            case 1: {
                double celsius;
                std::cout << "Enter temperature in Celsius: ";
                std::cin >> celsius;
                double fahrenheit = celsiusToFahrenheit(celsius);
                std::cout << celsius << "°C = " << fahrenheit << "°F" << std::endl;
                break;
            }
            case 2: {
                double fahrenheit;
                std::cout << "Enter temperature in Fahrenheit: ";
                std::cin >> fahrenheit;
                double celsius = fahrenheitToCelsius(fahrenheit);
                std::cout << fahrenheit << "°F = " << celsius << "°C" << std::endl;
                break;
            }
            case 3: {
                double a, b, c;
                std::cout << "Enter coefficients a, b, c for ax^2 + bx + c = 0:" << std::endl;
                std::cout << "a = ";
                std::cin >> a;
                std::cout << "b = ";
                std::cin >> b;
                std::cout << "c = ";
                std::cin >> c;
                quadraticRoots(a, b, c);
                break;
            }
            case 4: {
                double weight, height;
                std::cout << "Enter weight (in kg): ";
                std::cin >> weight;
                std::cout << "Enter height (in meters): ";
                std::cin >> height;
                calculateBMI(weight, height);
                break;
            }
            case 5: {
                int n;
                std::cout << "Enter n (1 to n): ";
                std::cin >> n;
                long long result = sumExceptDivisibleBy3(n);
                std::cout << "Sum of numbers from 1 to " << n << " (excluding multiples of 3): " << result << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
    
    return 0;
}
