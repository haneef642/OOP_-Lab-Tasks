#include <iostream>

using namespace std;

class Book {
private:
    string title;
    string isbn;
public:
    Book(string t, string i) : title(t), isbn(i) {}
    string getTitle() const { return title; }
    string getISBN() const { return isbn; }
};

class Catalog {
private:
    Book* books[10];
    int bookCount;
public:
    Catalog() : bookCount(0) {}
    void addBook(Book* book) {
        if (bookCount < 10) {
            books[bookCount++] = book;
        }
    }
    Book* findBook(string isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getISBN() == isbn) {
                return books[i];
            }
        }
        return nullptr;
    }
};

class Library {
private:
    Catalog catalog;
    Book* books[10];
    int bookCount;
    string name;
public:
    Library(string n) : name(n), bookCount(0) {}
    void addBook(Book* book) {
        if (bookCount < 10) {
            books[bookCount++] = book;
            catalog.addBook(book);
        }
    }
    void findBookInCatalog(string isbn) {
        Book* book = catalog.findBook(isbn);
        if (book) {
            cout << "Book found: " << book->getTitle() << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    Library library("City Library");
    Book book1("C++ Programming", "12345");
    Book book2("Data Structures", "67890");
    
    library.addBook(&book1);
    library.addBook(&book2);
    
    cout << "Searching for books:" << endl;
    library.findBookInCatalog("12345");
    library.findBookInCatalog("99999");
    
    return 0;
}

