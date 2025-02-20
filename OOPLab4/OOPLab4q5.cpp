#include <iostream>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem() {}

    MenuItem(string n, string t, double p) {
        name = n;
        type = t;
        price = p;
    }
};

class CoffeeShop {
private:
    string name;
    MenuItem menu[100];
    string orders[100];
    int menuCount;
    int orderCount;

public:
    CoffeeShop(string n) {
        name = n;
        menuCount = 0;
        orderCount = 0;
    }

    void addMenuItem(MenuItem item) {
        if (menuCount < 100) {
            menu[menuCount] = item;
            menuCount++;
        }
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuCount; i++) {
            if (menu[i].name == itemName) {
                if (orderCount < 100) {
                    orders[orderCount] = itemName;
                    orderCount++;
                }
                return "Order added!";
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 0; i < orderCount - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderCount--;
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders yet" << endl;
        } else {
            for (int i = 0; i < orderCount; i++) {
                cout << orders[i] << endl;
            }
        }
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuCount; j++) {
                if (orders[i] == menu[j].name) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuCount == 0) return "No items in the menu";
        int index = 0;
        for (int i = 1; i < menuCount; i++) {
            if (menu[i].price < menu[index].price) {
                index = i;
            }
        }
        return menu[index].name;
    }

    void drinksOnly() {
        for (int i = 0; i < menuCount; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << endl;
            }
        }
    }

    void foodOnly() {
        for (int i = 0; i < menuCount; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << endl;
            }
        }
    }
};

int main() {
    CoffeeShop shop("My CoffeeShop");

    shop.addMenuItem(MenuItem("Espresso", "drink", 2.5));
    shop.addMenuItem(MenuItem("Latte", "drink", 3.0));
    shop.addMenuItem(MenuItem("Sandwich", "food", 5.0));
    shop.addMenuItem(MenuItem("Croissant", "food", 4.0));

    cout << shop.addOrder("Espresso") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.dueAmount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;
    cout << "Drinks: " << endl;
    shop.drinksOnly();
    cout << "Foods: " << endl;
    shop.foodOnly();

    return 0;
}
