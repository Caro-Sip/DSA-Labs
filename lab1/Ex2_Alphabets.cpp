#include <iostream>
#include <string>
#include <cctype>

bool isVowel(char c){
    return std::string("aeiou").find(tolower(c)) != std::string::npos;
}

bool isConsonant(char c){
    c = tolower(c);
    int ascii = (int)c;

    for(int i = 97; i <= 122; i++){
        if (ascii == i) return true;
    }
    return false;
}

int main(){
    char c;
    std::cout << "Enter one singular character: ";
    std::cin >> c;

    if(isVowel(c)){
        std::cout << c << " is a vowel\n";
    }
    else if(isConsonant(c)){
        std::cout << c << " is a consonant\n";
    }
    else{
        std::cout << c << " is non-alphabetical\n";
    }

    return 0;
}