#include <iostream>

struct Element{
    int data;
    Element* next;
};

struct List {
    int n;
    Element* head;
    Element* tail;
};

