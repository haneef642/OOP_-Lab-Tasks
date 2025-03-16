#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance;
public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        }
    }

    virtual void display() {
        cout << "Account Number: " << accountNumber << " | Balance: $" << balance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int accNum, double bal) : BankAccount(accNum, bal) {}

    void applyInterest(double rate) {
        double interest = balance * rate;
        balance += interest;
        cout << "Interest Applied: $" << interest << " | New Balance: $" << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;
public:
    CheckingAccount(int accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Overdraft limit exceeded! Withdrawal denied." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        }
    }
};

class BusinessAccount : public BankAccount {
public:
    BusinessAccount(int accNum, double bal) : BankAccount(accNum, bal) {}

    void deposit(double amount) override {
        double tax = amount * 0.05;
        balance += (amount - tax);
        cout << "Deposited: $" << amount << " | Tax Deducted: $" << tax << " | New Balance: $" << balance << endl;
    }
};

class User {
public:
    virtual void accessAccount(BankAccount* acc) = 0;
    virtual ~User() {}
};

class Customer : public User {
public:
    void accessAccount(BankAccount* acc) override {
        acc->deposit(500);
        acc->withdraw(200);
    }
};

class Teller : public User {
public:
    void accessAccount(BankAccount* acc) override {
        acc->deposit(1000);
        acc->withdraw(500);
        cout << "Teller has access to freeze the account." << endl;
    }
};

class Manager : public User {
public:
    void accessAccount(BankAccount* acc) override {
        acc->deposit(2000);
        acc->withdraw(1000);
        cout << "Manager can override account limits and adjust settings." << endl;
    }
};

int main() {
    SavingsAccount savings(101, 1000);
    CheckingAccount checking(102, 500, 200);
    BusinessAccount business(103, 5000);

    vector<BankAccount*> accounts = {&savings, &checking, &business};

    cout << "--- Account Operations ---" << endl;
    for (BankAccount* acc : accounts) {
        acc->display();
        acc->deposit(500);
        acc->withdraw(1000);
        cout << "------------------" << endl;
    }

    Customer customer;
    Teller teller;
    Manager manager;

    cout << "--- User Role Actions ---" << endl;
    customer.accessAccount(&savings);
    teller.accessAccount(&checking);
    manager.accessAccount(&business);

    return 0;
}
