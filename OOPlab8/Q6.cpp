#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int employeeID;

public:
    void getData(int id) {
        employeeID = id;
    }

    void displayData() const {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
private:
    string name;
    double monthlyIncome;

public:
    void getData(int id, const string& employeeName, double income) {
        Person::getData(id);
        name = employeeName;
        monthlyIncome = income;
    }

    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
    }

    double bonus() const {
        return monthlyIncome * 0.05 * 12; // Annual bonus (5% of monthly income)
    }
};

class Accounts : public Person {
private:
    string name;
    double monthlyIncome;

public:
    void getData(int id, const string& employeeName, double income) {
        Person::getData(id);
        name = employeeName;
        monthlyIncome = income;
    }

    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
    }

    double bonus() const {
        return monthlyIncome * 0.05 * 12; // Annual bonus (5% of monthly income)
    }
};

int main() {
    Admin admin1, admin2;
    Accounts acc1, acc2;

    admin1.getData(101, "Alice", 5000);
    admin2.getData(102, "Bob", 6000);

    acc1.getData(201, "Charlie", 4500);
    acc2.getData(202, "David", 5500);

    cout << "\nAdmin Employee Details:\n";
    admin1.displayData();
    cout << "Bonus: " << admin1.bonus() << endl;
    cout << "\n";
    admin2.displayData();
    cout << "Bonus: " << admin2.bonus() << endl;

    cout << "\nAccounts Employee Details:\n";
    acc1.displayData();
    cout << "Bonus: " << acc1.bonus() << endl;
    cout << "\n";
    acc2.displayData();
    cout << "Bonus: " << acc2.bonus() << endl;

    return 0;
}
