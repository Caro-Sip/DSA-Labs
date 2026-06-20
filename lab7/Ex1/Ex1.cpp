#include <iostream>

const int SIZE = 5;
int stack[SIZE];
int top = -1;

bool isFull(){
    if(top == SIZE-1) return true;
    else return false;
}

bool isEmpty(){
    if(top == -1) return true;
    else return false;
}

void push(int data){
    if(isFull()){
        std::cout << "Stack overflow\n";
        return;
    }

    stack[++top] = data;
    std::cout << stack[top] << " is added\n";
    return;
}

int pop(){
    if(isEmpty()){
        std::cout << "Stack underflow\n";
        return -1;
    }

    int data = stack[top];
    stack[top--] = 0;
    return data;
}

int peek(){
    if(isEmpty()){
        std::cout << "Stack is empty\n";
        return -1;
    }
    return stack[top];
}

void displayStack(){
    if(isEmpty()) return;
    for(int i=top;i>=0;i--){
        std::cout << stack[i] <<  " ";
    }
    std::cout << std::endl;
}

int main(){
    displayStack();
    push(1);
    displayStack();
    push(2);
    displayStack();
    push(3);
    displayStack();
    push(4);
    displayStack();
    push(5);
    displayStack();
    push(6);
    displayStack();
    pop();
    displayStack();
    pop();
    displayStack();
    pop();
    displayStack();
    pop();
    displayStack();
    pop();
    displayStack();
    pop();
}