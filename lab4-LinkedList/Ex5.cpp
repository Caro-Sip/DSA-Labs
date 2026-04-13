#include <iostream>

struct Node{
    int number;
    Node *next;
};

struct ListNumber{
    int listLength;
    Node* head;
    Node* tail; 
};

ListNumber *createEmptyList(){
    ListNumber* ls = new ListNumber;

    ls->listLength = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

void add(int n, ListNumber* ls){
    try{
        Node *newNode = new Node;
        newNode->number = 0;
        newNode->next = nullptr;

        if(ls->listLength == 0){
            newNode->number = n;
            ls->head = newNode;
            ls->tail = newNode;            
        }
        else{
            newNode->number = n;
            ls->tail->next = newNode;
            ls->tail = newNode;
        }
        ls->listLength++;
    } 
    catch(const std::bad_alloc&){
        std::cerr << "Bibity bopity boo mem alloc failed";
    }
}

void printAllNodes(const Node *currentNode){
    while(currentNode != nullptr){
        std::cout << currentNode->number << " ";
        currentNode = currentNode->next;
    }
}

int sumListNumbers(const Node *currentNode){
    int sum = 0;

    while(currentNode != nullptr){
        sum += currentNode->number;
        currentNode = currentNode->next;        
    }
    return sum;
}

int main(){
    ListNumber *ls = createEmptyList();

    bool seenFirstZero = false;

    while(!seenFirstZero){ 
        std::cout << "Enter a number: ";
        int n = 0;
        std::cin >> n;
        
        // This logic follows a global zero, not zero in a row
        if(n == 0){
           if (!seenFirstZero){
                seenFirstZero = true;
                std::cout << "You entered 0; enter another to exit";
           }
           else {
                std::cout << "You entered 0 twice; EXITING";
                break;
           }
           continue;
        }
        
        add(n,ls);
    }

    std::cout << "All data in the list are: ";
    printAllNodes(ls->head);
    std::cout << "\nSummation of all numbers is: " << sumListNumbers(ls->head) << "\n";
}