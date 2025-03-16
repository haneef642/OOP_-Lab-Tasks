#include <iostream>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string g) : genre(g) {}

    virtual void displayDetails() {
        cout << "Genre: " << genre << endl;
    }

    virtual ~Books() {}
};

class Novel : public Books {
private:
    string title;
    string author;
public:
    Novel(string t, string a) : Books("Novel"), title(t), author(a) {}

    void displayDetails() override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

class Mystery : public Books {
private:
    string title;
    string author;
public:
    Mystery(string t, string a) : Books("Mystery"), title(t), author(a) {}

    void displayDetails() override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    Novel n1("Pride and Prejudice", "Jane Austen");
    Mystery m1("Sherlock Holmes", "Arthur Conan Doyle");

    Books* books[] = {&n1, &m1};

    cout << "--- Library Books ---" << endl;
    for (Books* book : books) {
        book->displayDetails();
        cout << "---------------------" << endl;
    }

    return 0;
}
