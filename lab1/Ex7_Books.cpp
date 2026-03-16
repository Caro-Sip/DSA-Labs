#include <iostream>
#include <vector>

//What dis, the library?

struct Book{
    int id;
    unsigned long isbn;
    std::string title;
    int year;
    std::vector<std::string> authors;
    double price;
};


void displayBookByISBN(Book books[], int size, unsigned long isbn){
    for (int i = 0; i < size; i++) {
        if (books[i].isbn == isbn) {
            // Found it - display this book
            std::cout << "Book " << books[i].id << ": " << books[i].title << std::endl;
            std::cout << "  ISBN: " << books[i].isbn << std::endl;
            std::cout << "  Year: " << books[i].year << std::endl;
            std::cout << "  Authors: ";
            for (int j = 0; j < books[i].authors.size(); j++) {
                if (j > 0) std::cout << ", ";
                std::cout << books[i].authors[j];
            }
            std::cout << std::endl;
            std::cout << "  Price: $" << books[i].price << std::endl;
            return;
        }
    }
    std::cout << "Book not found!" << std::endl;
    return;
}

void displayAllBooks(Book books[], int size){
    for (int i = 0; i < size; i++) {
        std::cout << "Book " << books[i].id << ": " << books[i].title << std::endl;
        std::cout << "  ISBN: " << books[i].isbn << std::endl;
        std::cout << "  Year: " << books[i].year << std::endl;
        std::cout << "  Authors: ";
        for (int j = 0; j < books[i].authors.size(); j++) {
            if (j > 0) std::cout << ", ";
            std::cout << books[i].authors[j];
        }
        std::cout << std::endl;
        std::cout << "  Price: $" << books[i].price << std::endl << std::endl;
    }
    return;
}

int main(){
    Book books[5] = {
        {1, 9781234567890, "Omniscient Reader's Viewpoint", 2020, {"Sing Shong"}, 14.99},
        {2, 9781234567901, "Supreme Magus", 2019, {"Legion20"}, 12.99},
        {3, 9781234567912, "Art of War", 500, {"Sun Tzu"}, 9.99},
        {4, 9781234567923, "Frankenstein's Monster", 1818, {"Mary Shelley"}, 11.99},
        {5, 9781234567934, "The Supreme Leader, Kim Jong Un", 2015, {"Historical Archive","Rando on Internet"}, 8.99}
    };
     
    // Di Calculate stack size of books and divide by how many bytes taken per headah
    int size = sizeof(books) / sizeof(books[0]);
    displayBookByISBN(books, size, 9781234567890);

    std::cout << "==================================\n";

    displayAllBooks(books, size);

    return 0;
}