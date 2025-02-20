#include <iostream>
using namespace std;

class Book {
    string title, author, publisher;
    double price;
    int stock;
public:
    Book() {}
    Book(string t, string a, string p, double pr, int s) {
        title = t;
        author = a;
        publisher = p;
        price = pr;
        stock = s;
    }
    bool isAvailable(string t, string a) {
        if (title == t && author == a) {
            return true;
        }
        return false;
    }
    void displayDetails() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPublisher: " << publisher << "\nPrice: " << price << "\nStock: " << stock << "\n";
    }
    bool sellCopies(int copies) {
        if (copies <= stock) {
            cout << "Total Cost: " << price * copies << "\n";
            stock -= copies;
            return true;
        }
        cout << "Required copies not in stock\n";
        return false;
    }
};

class Bookshop {
    Book inventory[100];
    int count;
public:
    Bookshop() {
        count = 0;
    }
    void addBook(Book b) {
        if (count < 100) {
            inventory[count] = b;
            count++;
        }
    }
    void searchBook(string title, string author) {
        for (int i = 0; i < count; i++) {
            if (inventory[i].isAvailable(title, author)) {
                inventory[i].displayDetails();
                int copies;
                cout << "Enter number of copies required: ";
                cin >> copies;
                inventory[i].sellCopies(copies);
                return;
            }
        }
        cout << "Book not available\n";
    }
};

int main() {
    Bookshop shop;
    shop.addBook(Book("Book1", "Author1", "Publisher1", 500.0, 10));
    shop.addBook(Book("Book2", "Author2", "Publisher2", 700.0, 5));
    string title, author;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    shop.searchBook(title, author);
    return 0;
}
