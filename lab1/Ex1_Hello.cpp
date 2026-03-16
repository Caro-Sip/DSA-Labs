#include <iostream>

struct Person
{
    std::string name;
    int age;
    char gender;
    std::string major;
};

void printPerson(Person p){
    std::string title = (p.gender == 'M' || p.gender == 'm') ? "Mr. " : "Ms. ";

    std::cout << "Hi, " << title << p.name << "! your age is " << p.age << " year old and you learn " << 
    p.major << "!" << std::endl;
    
    (p.age >= 18) ? std::cout << "You are eligible to vote!" : std::cout << "You are not eligible to vote!";
    std::cout << std::endl;
}

int main()
{
    Person p1 = {"Caro", 20, 'M', "Software Engineering"};
    Person p2 = {"Lyda", 23, 'F', "Software Engineering"};
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

    std::cout << "Your major: ";
    std::getline(std::cin, p3.major);

    printPerson(p1);
    printPerson(p2);
    printPerson(p3);

    return 0;
}