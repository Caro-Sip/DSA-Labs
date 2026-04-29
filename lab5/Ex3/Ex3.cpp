#include <iostream>

struct Product{
    int productId;
    std::string name;
    int price;
};

struct Element{
    Product product;
    Element* next;
};

struct ListProduct{
    int n;
    Element* head;
    Element* tail;
};

ListProduct* createEmptyList(){
    ListProduct* ls = new ListProduct();
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;

    return ls;
}

void addProducToBegin(ListProduct* const ls, Product product){
    if(ls == nullptr){
        std::cout << "Cannot add product to list becuase list is null";
    }

    Element* e = new Element();
    e->product = product;
    e->next = nullptr;
    if(ls->n == 0){
        ls->head = e;
        ls->tail = e;
    }
    else if (ls->n > 0){
        e->next = ls->head;
        ls->head = e;
    }

    ls->n++;
    return;
}

void addProducToEnd(ListProduct* const ls, Product product){
    if(ls == nullptr){
        std::cout << "Cannot add product to list becuase list is null";
    }

    Element* e = new Element();
    e->product = product;
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

void display(ListProduct* const ls){
    Element* e = ls->head;
    // while(e != nullptr){
    //     std::cout << "Product: " << e->product.name << "\n";
    //     std::cout << "ID: " << e->product.productId << "\n";
    //     std::cout << "Price: " << e->product.price << "\n";
    //     std::cout << "---\n";

    //     e = e->next;
    // }
    for(Element* e = ls->head; e != nullptr; e = e->next){
        std::cout << "Product: " << e->product.name << "\n";
        std::cout << "ID: " << e->product.productId << "\n";
        std::cout << "Price: " << e->product.price << "\n";
        std::cout << "---\n";
    }
}

int main(){
    ListProduct* ls = createEmptyList();
    
    Product p[] = {
        {111,"coca",65},
        {222, "Shampo",30},
        {333, "Shrimp", 40},
        {444, "Matcha", 70}
    };

    for(Product t : p){
        if(t.price < 50){
            addProducToBegin(ls, t);
        }
        else{
            addProducToEnd(ls,t);
        }
    }

    display(ls);

    return 0;
}
