#include <iostream>
#include <cmath>

int findBinary(int num);

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
    int numBinary = findBinary(data);
    e->data = numBinary;
    e->next = s->top;
    s->top = e;
    s->n++;
    return;
}

int pop(Stack* s){
    if(!s && s->top == nullptr) {
        std::cout << "Stack is empty";
        return -1;
    }
    Element* e = s->top;
    s->top = e->next;
    int data = e->data;
    delete e;
    s->n--;
    return data;
}

int findBinary(int num){
    if(num == 0){
        return 0;
    }

    int quotient = num / 2;

    return findBinary(quotient)*10 + num % 2;
}

int calculateBinary(int num){
    int binary = 0;

    for(int i = 0; num > 0; i++){
        binary += num % 2 * pow(10,i);
        num /= 2;
    }
   
    return binary;
}

void display(Stack* s){
    if(!s || s->top == nullptr){
        std::cout << "Stack is empty";
        return;
    }

    std::cout << "Stack elements:\n";

    Element* e = s->top;
    while(e!=nullptr){
        std::cout << e->data << " ";
        e = e->next;
    }
    std::cout << std::endl;
    return;
}

int main(){
    Stack* stack = createStack();
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    push(stack, 11);
    display(stack);
    return 0;
}