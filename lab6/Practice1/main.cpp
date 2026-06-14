#include <iostream>

// a. create two struct and one create func

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

// b. addEnd()

void addEnd(List* ls, int data){
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    e->prev = ls->tail;

    if(ls->n == 0){
        ls->head = e;
    }
    else{
        e->prev->next = e;
    }

    ls->tail = e;
    ls->n++;
    return;
}

// c. addBeg()

void addBeg(List* ls, int data){
    Element* e = new Element;
    e->data = data;
    e->prev = nullptr;
    e->next = ls->head;

    if(ls->n == 0){
        ls->tail = e;
    }
    else{
        ls->head->prev = e;
    }

    ls->head = e;
    ls->n++;
}

// d. display()

void display(List* ls){
    Element* e = ls->head;
    while(e != nullptr){
        std::cout << e->data << " ";
        e = e->next;
    }
    std::cout << std::endl;
}

// e. deleteBeg()

void deleteBeg(List* ls){
    if(ls->n == 0) return;
    
    Element* temp = ls->head;
    ls->head = ls->head->next;

    if(ls->head != nullptr){
        ls->head->prev = nullptr;
    }
    else{
        ls->tail = nullptr;
    }

    delete temp;
    ls->n--;
}

// f. deleteEnd()

void deleteEnd(List* ls){
    if(ls->n == 0) return;

    Element* temp = ls->tail;
    ls->tail = ls->tail->prev;
    if(ls->tail != nullptr){
        ls->tail->next = nullptr;
    }
    else{
        ls->head = nullptr;
    }

    delete temp;
    ls->n--;
}