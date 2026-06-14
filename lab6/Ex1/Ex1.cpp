#include <iostream>

struct Node{
    int data;
    Node* prev;
    Node* next;
};

struct List{
    int n;
    Node* head;
    Node* tail;
};

List* createEmptyList(){
    List* ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

void addBeg(List* const ls, int data){
    if(ls == nullptr){
        std::cout << "The list object doesn't exist";
        return;
    }

    if(ls->n == 0){
        Node* node = new Node;
        node->data = data;
        node->prev = nullptr;
        node->next = nullptr;
        
        ls->head = node;
        ls->tail = node;
        ls->n++;
        return;
    }

    Node* node = new Node;
    node->data = data;
    node->prev = nullptr;
    node->next = nullptr;

    ls->head->prev = node;
    node->next = ls->head;
    ls->head = node;
    ls->n++;
}

void addEnd(List* ls, int data){
    if(ls == nullptr){
        std::cout << "List object is empty";
        return;
    }

    if(ls->n==0){
        addBeg(ls, data);
        return;
    }

    Node* node = new Node;
    node->data = data;
    node->prev = nullptr;
    node->next = nullptr;

    ls->tail->next = node;
    node->prev = ls->tail;
    ls->tail = node;
    ls->n++;
}

void addPos(List* ls, int pos, int data){
    if(ls == nullptr){
        std::cout << "List object is empty";
        return;
    }

    if(ls->n==0){
        addBeg(ls, data);
        return;
    }

    if(pos == 0){
        addBeg(ls, data);
        return;
    }

    if(pos == ls->n){
        addEnd(ls, data);
        return;
    }

    Node* current = ls->head;
    for(int i=0;i<pos-1;i++){
        current = current->next;
    }

    Node* node = new Node;
    node->data = data;
    node->prev = nullptr;
    node->next = nullptr;

    node->prev = current;
    node->next = current->next;

    current->next = node;
    if(node->next != nullptr) // fix: set successor's prev to the new node
        node->next->prev = node;
    ls->n++;
}

void display(List* ls){
    if(ls == nullptr) return;
    Node* n = ls->head;
    while(n != nullptr){
        std::cout << n->data << '\n';
        n = n->next;
    }
    return;
}

int main(){
    List* ls = createEmptyList();

    addBeg(ls,1);
    addEnd(ls,3);
    addPos(ls,1,2);
    display(ls);
    return 0;
}