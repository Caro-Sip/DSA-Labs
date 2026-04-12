#include <iostream>
#include <string>

struct Student{
    int id;
    std::string name;
    int year;
    std::string program_degree;
};

struct Node {
    Student student;
    Node *next;
};

struct ListStudent {
    int n;
    Node *head;
    Node *tail;    
};

// Create an empty list
ListStudent* createEmptyList() {
    ListStudent *list = new ListStudent();
    list->n = 0;
    list->head = nullptr;
    list->tail = nullptr;
    return list;
}

// Add a student to the list
void add(Student s, ListStudent *LS) {
    Node *newNode = new Node();
    newNode->student = s;
    newNode->next = nullptr;
    
    if (LS->head == nullptr) {
        // First student
        LS->head = newNode;
        LS->tail = newNode;
    } else {
        // Add to end of list
        LS->tail->next = newNode;
        LS->tail = newNode;
    }
    
    LS->n++;
}

int main() {
    // Create an empty list
    ListStudent *classList = createEmptyList();
    
    // Add 5 students
    add({1, "Alice Johnson", 2, "Computer Science"}, classList);
    add({2, "Bob Smith", 2, "Computer Science"}, classList);
    add({3, "Carol Williams", 1, "Engineering"}, classList);
    add({4, "David Brown", 3, "Data Science"}, classList);
    add({5, "Eve Davis", 2, "Software Engineering"}, classList);
    
    // Display the students
    std::cout << "Total students: " << classList->n << std::endl;
    std::cout << "\nStudent List:\n";
    
    Node *current = classList->head;
    while (current != nullptr) {
        std::cout << "ID: " << current->student.id 
                  << " | Name: " << current->student.name 
                  << " | Year: " << current->student.year 
                  << " | Program: " << current->student.program_degree << std::endl;
        current = current->next;
    }
    
    return 0;
}