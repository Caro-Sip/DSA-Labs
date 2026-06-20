#include <iostream>

struct Element{
    char c;
    Element* next;
};

struct Stack{
    int n;
    Element* top;
};

void push(Stack* s, char c){
    Element* e = new Element;
    e->c = c;
    e->next = s->top;
    s->top = e;
    s->n++;
    return;
}

char pop(Stack* s){
    if(!s || s == nullptr){
        std::cout << "Stack is empty\n";
        return '1';
    }
    Element* e = s->top;
    char c = e->c;
    s->top = e->next;
    delete e;
    s->n--;
    return c;
}

void displayStack(Stack* s){
    if(!s || s->top == nullptr){
        std::cout << "Stack is empty\n";
        return;
    }
    Element* e = s->top;
    while(e != nullptr){
        std::cout << e->c;
        e = e->next;
    }
    std::cout << std::endl;
    return;
}

Stack* createStack(){
    Stack* s = new Stack;
    s->n = 0;
    s->top = nullptr;
    return s;
}

int main(){
    Stack* s = createStack();
    char c = ' ';
    while(true){
        std::cout << "The Stack\n";
        displayStack(s);
        std::cout << "Input any character(* to pop; 0 to exit): ";
        std::cin >> c;
        
        if(c == '*'){
            pop(s);
            continue;
        }

        if(c == '0'){
            break;
        }

        push(s,c);

    }
}