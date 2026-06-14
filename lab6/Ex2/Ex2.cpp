#include <iostream>
#include <ctime>
#include <cstdlib>

struct Element{
    int data;
    Element* prev;
    Element* next;
};

struct List{
    int n;
    Element* head;
    Element* tail; 
};

List* createEmptyList(){
    List* ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;

    return ls;
}

void addBeg(List* ls, int data){
    Element* e = new Element;
    e->data = data;
    e->next = ls->head;
    e->prev = nullptr;

    if(ls->n == 0){
        ls->tail = e;
    }
    else{
        ls->head->prev = e;
    }

    ls->head = e;
    ls->n++;

    return;
}

void addEnd(List* ls, int data){
    Element* e = new Element;
    e->data = data;
    e->prev = ls->tail;
    e->next = nullptr;

    if(ls->n == 0){
        ls->head = e;
    }
    else{
        ls->tail->next = e;
    }

    ls->tail = e;
    ls->n++;
    return;
}

void addPos(List* ls, int data, int pos){
    if(pos < 0 || pos > ls->n){
        return;
    }

    if(pos == 0){
        addBeg(ls,data);
        return;
    }

    if(pos == ls->n){
        addEnd(ls,data);
        return;
    }

    Element* current = ls->head;
    for(int i = 0; i < pos-1; i++){
        current = current->next;
    }

    Element* e = new Element;
    e->data = data;
    e->next = current->next;
    e->prev = current;

    current->next->prev = e;
    current->next = e;
    ls->n++;
    return;
}

void display(List* ls){
    Element* e = ls->head;
    while(e != nullptr){
        std::cout << e->data << " ";
        e = e->next;
    }
    std::cout << std::endl;
    return;
}

int main(){
    List* ls = createEmptyList();
    
    int n = 0;
    std::cout << "Input a number n: ";
    std::cin >> n;

    std::srand(std::time(0)); 

    for(int i = 0; i < n; i++){
        
        // Generate a number between 1 and 10
        int random_num = (std::rand() % 100) + 1; 

        addBeg(ls,random_num);
    }

    display(ls);

    Element* e = ls->head;
    int sum;
    while(e != nullptr){
        sum += e->data;
        e = e->next;
    }

    double avg = (double) sum / ls->n;

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Average: "<< avg<< "\n";

    return 0;
}