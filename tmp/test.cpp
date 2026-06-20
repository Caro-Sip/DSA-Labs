#include <iostream>

class A{
    public:
        std::string text;
        A(std::string s, std::string t){
            this->text = s;
            this->text = t;
        }
};

class B{
    public:
        A attri_a;
        B(int a, A input_a, int b) : attri_a(input_a){
        }
};