#include <iostream>
#include <string>

struct Student{
    int id;
    std::string name;
    int year;
    std::string program;
};

struct Node{
    Student student;
    Node* next;
};

struct ListStudent{
    int listLength;
    Node head;
    Node tail;
};