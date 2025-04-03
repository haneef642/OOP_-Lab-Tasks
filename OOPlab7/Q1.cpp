#include <iostream>
using namespace std;

class Account {
protected:
    string accountNumber, accountHolderName,  accountType;
    double balance;


public:

    Account(string num, string name, double bal, string type = "General") : accountNumber(num), accountHolderName(name), balance(bal), accountType(type) {}
    virtual void deposit(double amount) { balance += amount; }

    virtual bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }

    virtual double calculateInterest() { return 0; }

    virtual void printStatement() { cout << "Account Statement: " << balance << endl; }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
    double interestRate, minimumBalance;

public:

    SavingsAccount(string num, string name, double bal, double rate, double minBal)

        : Account(num, name, bal, "Savings"), interestRate(rate), minimumBalance(minBal) {}
    double calculateInterest() override { return balance * interestRate / 100; }
};

class FixedDepositAccount : public Account {

    double fixedInterestRate, maturityDate;
public:

    FixedDepositAccount(string num, string name, double bal, double rate, double maturity)
        : Account(num, name, bal, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}
    double calculateInterest() override { return balance * fixedInterestRate / 100; }
};

int main() {


    SavingsAccount sa("12345", "John Doe", 5000, 3.5, 1000);
    FixedDepositAccount fda("67890", "Jane Doe", 10000, 5.0, 12);
    cout << "Savings Interest: " << sa.calculateInterest() << endl;
    cout << "Fixed Deposit Interest: " << fda.calculateInterest() << endl;

}