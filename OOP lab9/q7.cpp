#include <iostream>
using namespace std;

class Person {
public:
    virtual void getdata() = 0;
    virtual void display() = 0;
    virtual void bonus() = 0;
};

class Admin : virtual public Person {
protected:
    double salary;
public:
    void getdata() {
        salary = 5000;
    }
    void display() {
        cout << "Admin salary: " << salary << "\n";
    }
    void bonus() {
        cout << "Admin bonus: " << salary * 0.1 << "\n";
    }
};

class Account : virtual public Person {
protected:
    double income;
public:
    void getdata() {
        income = 4000;
    }
    void display() {
        cout << "Account income: " << income << "\n";
    }
    void bonus() {
        cout << "Account bonus: " << income * 0.05 << "\n";
    }
};

class Master : public Admin, public Account {
public:
    void getdata() {
        Admin::getdata();
        Account::getdata();
    }

    void display() {
        Admin::display();
        Account::display();
    }

    void bonus() {
        Admin::bonus();
        Account::bonus();
    }
};

int main() {
    Person* p;
    Master m;
    p = &m;
    p->getdata();
    p->display();
    p->bonus();
}
