#include <iostream>

struct Element{
    int data;
    Element* next;
};

struct Stack{
    int n;
    Element* top;
};

Stack* createStack(){
    Stack* s = new Stack;
    s->n = 0;
    s->top = nullptr;
    return s;
}

void push(Stack* s, int data){
    Element* e = new Element;
    e->data = data;
    e->next = s->top;
    s->top = e;
    s->n++;
    return;
}

int pop(Stack* s){
    if(s->top == nullptr) {
        std::cout << "Stack is empty";
        return -1;
    }
    Element* e = s->top;
    int data = e->data;
    s->top = e->next;
    delete e;
    s->n--;
    return data;
}

int 

int main(){

}