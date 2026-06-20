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

int peek(Stack* s){
    if(!s || s->top == nullptr) {
        std::cout << "Stack is empty\n";
        return -1;
    }
    return s->top->data; 
}

bool isEmpty(Stack* s){
    return s->n==0;
}

int getSize(Stack* s){
    return s->n;
}

void clearStack(Stack* s){
    while(s->top != nullptr){
        pop(s);
    }
    return;
}

void display(Stack* s){
    if(isEmpty(s)){
        std::cout << "Stack is empty\n";
        return;
    }
    std::cout << "Stack elements (top to bottom)\n";
    Element* e = s->top;
    while(e!= nullptr){
        std::cout << e->data << " ";
        e = e->next;
    }
    std::cout << "\n";
}

int main(){
    Stack* s = createStack();
    
    // Redundant push operations
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    display(s);
    
    // Redundant push operations
    push(s, 60);
    push(s, 70);
    push(s, 80);
    display(s);
    
    // Redundant pop operations
    pop(s);
    pop(s);
    display(s);
    
    // Redundant push operations
    push(s, 90);
    push(s, 100);
    display(s);
    
    // Redundant pop operations
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    display(s);
    
    return 0;
}
