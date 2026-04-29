#include <iostream>

struct Element{
    std::string name;
    Element* next;
};

struct List{
    int n;
    Element* head;
    Element* tail;
};

List* createList(){
    List* ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

void addPerson(List* const ls, std::string name){
    if(ls == nullptr){
        std::cout << "List is a nullptr";
        return;
    }
    
    Element* e = new Element();
    e->name = name;
    e->next = nullptr;
    
    if(ls->n == 0){
        ls->head = e;
        ls->tail = e;
    }
    else if(ls->n > 0){
        ls->tail->next = e;
        ls->tail = e;
    }

    ls->n++;

    return;
}

void displayList(const List* ls){
    if(ls == nullptr){
        std::cout << "Cannot display list from a nullptr";
        return;
    }

    for(Element* e = ls->head; e != nullptr; e = e->next){
        std::cout << "Name: " << e->name << '\n';
    }
    return;
}

int main(){
    List* ls = createList();

    for(int i = 'A'; i < 'A' + 26; i++){
        addPerson(ls, std::string(1,(char) i));
    }

    addPerson(ls,"Caro");
    addPerson(ls,"Both");
    addPerson(ls,"Vanheng");
    addPerson(ls,"Hengrith");
    addPerson(ls,"In");
    addPerson(ls,"Sathya");

    displayList(ls);
    
    return 0;
}