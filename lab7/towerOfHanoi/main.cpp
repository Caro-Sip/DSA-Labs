#include <iostream>
#include <string>
#include <cmath>

struct Element{
    int data;
    Element* next;
};

struct Stack{
    Element* top;
    int n;
    char name; // letter of the stack
};

Stack* createStack(char name){
    Stack* s = new Stack;
    s->top = nullptr;
    s->n =0;
    s->name = name;
    return s;
}

void push(Stack* s, int data){
    Element* e = new Element;
    e->data = data;
    e->next = s->top;
    s->top = e;
    s->n++;
}

int pop(Stack* s){
    if (s->top == nullptr) return -1;
    Element* e = s->top;
    s->top = s->top->next;
    int value = e->data;
    delete e;
    s->n--;
    return value;
}

int peek(Stack* s){
    if(!s || s->top == nullptr) return -1;
    return s->top->data;
}

void display(Stack* s){
    std::cout << "Rod " << s->name << ": " << std::endl;
    Element* e = s->top;
    while(e != nullptr){
        std::cout << e->data << std::endl;
        e = e->next;
    }
    std::cout << std::endl;
}

void displayAll(Stack* A, Stack* B, Stack* C){
    display(A);
    display(B);
    display(C);
    std::cout << "--------------\n";
    return;
}

Stack* getRod(char name, Stack* A, Stack* B, Stack* C){
    if(name == 'A') return A;
    if(name == 'B') return B;
    if(name == 'C') return C;
    return nullptr;
}

bool moveDisk(Stack* from, Stack* to){
    int fromTop = peek(from);
    int toTop = peek(to);
    
    if(fromTop == -1){
        std::cout << "Rod: " << from->name << " ia empty\n";
        return false;
    }

    if(toTop != -1 && fromTop > toTop){
        std::cout << "Invalid move: " << fromTop << " on " << toTop << std::endl;
        return false;
    }

    int movedDisk = pop(from);
    push(to, movedDisk);

    std::cout << "Moved disk " << movedDisk << " from Rod " << from->name << " to Rod " << to->name << std::endl;
    return true;
}

int main(){
    int n;
    std::cout << "Enter number of disks: ";
    std::cin >> n;

    int moveCount = 0;
    int minMoves = pow(2,n) -1;

    Stack* A = createStack('A');
    Stack* B = createStack('B');
    Stack* C = createStack('C');

    for(int i=n ; i>=1; i--){
        push(A,i);
    }

    displayAll(A, B, C);

    std::string input;
    while(true){
        std::cout << "Enter move (e.g AB to move from A to B, Q to quit): ";
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore();

        if(input == "Q" || input == "q") break;
        if(input.length() != 2){
            std::cout << "Invalid input, AB or BC or Q\n";
            continue;
        }

        char fromRod = toupper(input[0]);
        char toRod = toupper(input[1]);
        
        Stack* from = getRod(fromRod, A, B, C);
        Stack* to = getRod(toRod, A, B, C);

        if(!from || !to){
            std::cout << "Invalid Rod name. Use A B or C\n";
            continue;
        }

        if(from == to){
            std::cout << "Cannot move to the same rod\n";
            continue;
        }

        moveDisk(from, to);
        moveCount++;
        std::cout << "Count: " << moveCount << std::endl;
        displayAll(A, B, C);

        if(C->n==n){
            std::cout << "Congratulation, game finishsed\n";
            std::cout << "Total moves: " << moveCount << "\n";

            if(moveCount == minMoves){
                std::cout << "Perfect solution\n";
            }
            else{
                std::cout << "try again to improve moves to " << minMoves;
            }
            break;
        }
    }
    return 0;
}