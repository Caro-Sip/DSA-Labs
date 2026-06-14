#include <iostream>

// a
struct Student{
    std::string name;
    int id;
};

struct Element{
    Student student;
    Element* prev;
    Element* next;
};

struct StudentList{
    int n;
    Element* head;
    Element* tail;
};

StudentList* createEmptyList(){
    StudentList* ls = new StudentList;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

// b. add student
void addBeg(StudentList* ls, Student student){
    Element* e = new Element;
    e->student = student;
    e->prev = nullptr;
    e->next = ls->head;

    if(ls->n == 0){
        ls->tail = e;
    }
    else{
        ls->head->prev = e;
    }

    ls->head = e;
    ls->n++;
}

// c. add student at end

void addEnd(StudentList* ls, Student student){
    Element* e = new Element;
    e->student = student;
    e->next = nullptr;
    e->prev = ls->tail;

    if(ls->n == 0){
        ls->head = e;
    }
    else{
        ls->tail->next = e;
    }

    ls->tail = e;
    ls->n++;
}

// d. display number of students and students in list

void display(StudentList* ls){
    Element* e = ls->head;
    for(int i = 1; i <= ls->n; i++){
        std::cout << i << ": " << e->student.id << " " << e->student.name << "\n";
        e = e->next;
    }
    std::cout << std::endl;
}

// e. display by id
void displayById(StudentList* ls, int id){
    Element* e = ls->head;
    while(e != nullptr){
        if(e->student.id == id){
            std::cout << id << " is " << e->student.name << "\n";
            return;
        }
        e = e->next;
    }

    std::cout << "Student id not found";
    return;
}

// f. update by id
void updateById(StudentList* ls, int id, std::string name){
    Element* e = ls->head;
    while(e != nullptr){
        if(e->student.id == id){
            std::string tmpName = e->student.name;
            e->student.name = name;
            std::cout << "name of student " << id << " is changed from " << tmpName << " to " << e->student.name;
            return;
        }

        e = e->next;
    }

    std::cout << "Student id not found";
    return;
}