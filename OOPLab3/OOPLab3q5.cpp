#include <iostream>
using namespace std;

class Book {
private:
    string bookName;
    string ISBN;
    string author;
    string publisher;

public:
    Book(string bookName, string ISBN, string author, string publisher) {
        this->bookName = bookName;
        this->ISBN = ISBN;
        this->author = author;
        this->publisher = publisher;
    }

    string getBookName() {
        return this->bookName;
    }

    string getISBN() {
        return this->ISBN;
    }

    string getAuthor() {
        return this->author;
    }

    string getPublisher() {
        return this->publisher;
    }

    string getBookInfo() {
        return "Book Name: " + this->bookName + "\nISBN: " + this->ISBN +
               "\nAuthor: " + this->author + "\nPublisher: " + this->publisher + "\n";
    }
};

int main() {
    Book books[5] = {
        Book("The Great Gatsby", "9780743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("1984", "9780451524935", "George Orwell", "Signet Classic"),
        Book("To Kill a Mockingbird", "9780061120084", "Harper Lee", "J.B. Lippincott & Co."),
        Book("Moby-Dick", "9781503280786", "Herman Melville", "CreateSpace"),
        Book("Pride and Prejudice", "9781503290563", "Jane Austen", "CreateSpace")
    };

    for (int i = 0; i < 5; i++) {
        cout << books[i].getBookInfo() << endl;
    }

    return 0;
}

