#include <iostream>

struct Element {
    char data = 0;
    Element *next = nullptr;
};

struct List {
    int n = 0;
    Element *head = nullptr;
    Element *tail = nullptr;
};

List *createList(){
    List *ls = new List();

    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;

    return ls;
}

void addPerson(List *ls, char data){
    if(ls->n == 0){
        Element *node = new Element();
        node->data = data;

        ls->head = node;
        ls->tail = node;
    }
    else{
        Element *node = new Element();
        node->data = data;

        ls->tail->next = node;
        ls->tail = node;
    }

    ls->n++;
}

void displayAllData(const Element *node){
    int counter = 0;
    while(node != nullptr){
        std::cout << "Element #" << counter + 1 << node->data << '\n';
        node = node->next;
        counter++;
    }
}

int main(){
    List *ls = createList();
    
    for(int i = 0; i < 26; i++){
        addPerson(ls, (char) 'A' + i );
    }

    displayAllData(ls->head);

    return 0;
}