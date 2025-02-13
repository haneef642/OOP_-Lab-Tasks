#include <iostream>
using namespace std;

class Glass {
public:
    int LiquidLevel;

    Glass() {
        LiquidLevel = 200;
    }

    void Drink(int milliliters) {
        if (milliliters > 0 && milliliters <= LiquidLevel) {
            LiquidLevel -= milliliters;
            if (LiquidLevel < 100) {
                Refill();
            }
        } else {
            cout << "Invalid amount! Cannot drink more than available liquid." << endl;
        }
    }

    void Refill() {
        LiquidLevel = 200;
        cout << "Glass refilled to 200 ml." << endl;
    }
};

int main() {
    Glass glass;
    string command;
    int amount;

    while (true) {
        cout << "Enter 'drink' followed by amount or 'exit' to stop: ";
        cin >> command;

        if (command == "exit") {
            cout << "Exiting program." << endl;
            break;
        } else if (command == "drink") {
            cin >> amount;
            glass.Drink(amount);
            cout << "Current Liquid Level: " << glass.LiquidLevel << " ml" << endl;
        } else {
            cout << "Invalid command! Use 'drink <amount>' or 'exit'." << endl;
        }
    }

    return 0;
}

