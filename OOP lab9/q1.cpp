#include <iostream>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDeposit;
    double dailyWithdraw;
    const double maxDailyDeposit = 5000;
    const double maxDailyWithdraw = 3000;

public:
    Wallet() : balance(0), dailyDeposit(0), dailyWithdraw(0) {}

    bool deposit(double amount) {
        if (amount <= 0 || dailyDeposit + amount > maxDailyDeposit) return false;
        balance += amount;
        dailyDeposit += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || dailyWithdraw + amount > maxDailyWithdraw || amount > balance) return false;
        balance -= amount;
        dailyWithdraw += amount;
        return true;
    }

    double getBalance() {
        return balance;
    }
};

class User {
private:
    int userID;
    string name;
    Wallet wallet;

public:
    User(int id, string n) : userID(id), name(n) {}

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    double checkBalance() {
        return wallet.getBalance();
    }
};

int main() {
    User u1(1, "Ali");
    User u2(2, "Sara");

    u1.deposit(2000);
    u1.withdraw(500);
    u2.deposit(6000);
    u2.withdraw(200);

    cout << u1.checkBalance() << endl;
    cout << u2.checkBalance() << endl;

    return 0;
}
