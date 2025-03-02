#include <iostream>

using namespace std;

struct MenuItem {
    string name;
    double price;
    string type;
};

class CoffeeShop {
public:
    const string name;
    MenuItem menu[10];
    string orders[10];
    int menuSize, orderCount;

    CoffeeShop(string shopName, MenuItem shopMenu[], int size) : name(shopName), menuSize(size), orderCount(0) {
        for (int i = 0; i < size; i++) menu[i] = shopMenu[i];
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                orders[orderCount++] = itemName;
                return "Order added";
            }
        }
        return "Item not available";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string order = orders[0];
            for (int i = 0; i < orderCount - 1; i++) orders[i] = orders[i + 1];
            orderCount--;
            return "Order ready";
        }
        return "All orders done";
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (orders[i] == menu[j].name) total += menu[j].price;
            }
        }
        return total;
    }
};

int main() {
    MenuItem menu[] = {
        {"Coffee", 2.5, "drink"},
        {"Tea", 2.0, "drink"},
        {"Sandwich", 5.0, "food"},
        {"Cake", 4.0, "food"}
    };

    CoffeeShop shop("JavaCafe", menu, 4);
    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Burger") << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Total due " << shop.dueAmount() << endl;
    
    return 0;
}

