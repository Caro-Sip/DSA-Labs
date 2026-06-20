#include <iostream>

struct Element{
    char character;
    Element* next;
};

struct Stack{
    int n;
    Element* top;
};

void push(Stack* s, char character){
    Element* e = new Element;
    e->character = character;
    e->next = s->top;
    s->top = e;
    s->n++;
    return;
}

char pop(Stack* s){
    if(s->top == nullptr){
        std::cout << "Stack is empty\n"; 
        return -1;
    }
    Element* e = s->top;
    char data = e->character;
    s->top = e->next;
    delete e;
    s->n--;
    return data;
}

bool isEmpty(Stack* s){
    if()
}

void displayStack(Stack* s){
    while()

}