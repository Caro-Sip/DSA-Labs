#include <iostream>


struct Person{
    std::string name;
    uint8_t age;
    char gender;
    int salary;
};

double calculateTax(Person p){
    if (p.gender == 'm'){
        if (p.salary < 300){
            return p.salary*0;
        }
        else if (p.salary >= 300 && p.salary < 500){
            return p.salary*0.035;
        }
        else if (p.salary >= 500 && p.salary < 1000){
            return p.salary*0.07;
        }
        else if (p.salary >= 1000){
            return p.salary*0.095;
        }
    }
    else if (p.gender == 'f'){
        if (p.salary < 300){
            return p.salary*0;
        }
        else if (p.salary >= 300 && p.salary < 500){
            return p.salary*0.035;
        }
        else if (p.salary >= 500 && p.salary < 1000){
            return p.salary*0.065;
        }
        else if (p.salary >= 1000){
            return p.salary*0.08;
        }
    }
    return 0;
}

void printGrossSalary(Person p){
    double tax = calculateTax(p);
    std::cout << "Hello " << p.name << ", your salary is " << p.salary << " USD and you are subjected to " << tax << " USD in tax\n";

    std::cout << "Your grossing salary is: " << (p.salary - tax) << "USD" << std::endl;
    return;
}

int main(){
    Person p1 = {"Caro", 20, 'm', 600};
    Person p2 = {"Lyda", 23, 'm', 1020};
    Person p3;

    std::cout << "Your name: ";
    std::getline(std::cin, p3.name);

    std::cout << "Your age: ";
    std::cin >> p3.age;
    std::cin.ignore();  // Clear the newline

    std::cout << "Your gender(M or F): ";
    std::cin >> p3.gender;
    p3.gender = tolower(p3.gender);
    std::cin.ignore();  // Clear the newline

    std::cout << "Your salary: ";
    std::cin >> p3.salary;

    printGrossSalary(p1);
    printGrossSalary(p2);
    printGrossSalary(p3);

    return 0;
}