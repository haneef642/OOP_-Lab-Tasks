#include <iostream>
#include <vector>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int empId, string empName) : id(empId), name(empName) {}

    virtual void showDetails() {
        cout << "ID: " << id << " | Name: " << name << endl;
    }

    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder(string order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder(string order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, string empName) : Employee(empId, empName) {}

    void takeOrder(string order) override {
        cout << name << " (Waiter) took order: " << order << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, string empName) : Employee(empId, empName) {}

    void prepareOrder(string order) override {
        cout << name << " (Chef) is preparing: " << order << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, string empName) : Employee(empId, empName) {}

    void generateBill(double amount) override {
        cout << name << " (Cashier) generated a bill of $" << amount << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, string empName) : Employee(empId, empName) {}

    void takeOrder(string order) override {
        cout << name << " (Manager) took order: " << order << endl;
    }

    void generateBill(double amount) override {
        cout << name << " (Manager) generated a bill of $" << amount << " with a 10% discount!" << endl;
    }
};

class Menu {
protected:
    string itemName;
    double price;
public:
    Menu(string name, double cost) : itemName(name), price(cost) {}

    virtual double calculateCost() {
        return price;
    }

    virtual void showMenu() {
        cout << itemName << " - $" << price << endl;
    }

    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    FoodMenu(string name, double cost) : Menu(name, cost) {}

    double calculateCost() override {
        return price; 
    }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu(string name, double cost) : Menu(name, cost) {}

    double calculateCost() override {
        return price * 1.1; 
    }
};

int main() {
    Waiter waiter(101, "Alice");
    Chef chef(102, "Bob");
    Cashier cashier(103, "Charlie");
    Manager manager(104, "David");

    vector<Employee*> employees = {&waiter, &chef, &cashier, &manager};

    cout << "--- Employee Details ---" << endl;
    for (Employee* emp : employees) {
        emp->showDetails();
    }

    cout << "--- Order Processing ---" << endl;
    waiter.takeOrder("Pasta");
    chef.prepareOrder("Pasta");
    cashier.generateBill(15.0);
    manager.takeOrder("Steak");
    manager.generateBill(25.0);

    cout << "--- Menu Prices ---" << endl;
    FoodMenu food("Burger", 8.0);
    BeverageMenu drink("Coffee", 3.0);

    food.showMenu();
    drink.showMenu();
    cout << "Total cost (including beverage tax): $" << food.calculateCost() + drink.calculateCost() << endl;

    return 0;
}
