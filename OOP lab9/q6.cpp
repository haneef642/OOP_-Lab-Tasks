#include <iostream>
using namespace std;

class Car {
protected:
    int model;
    double price;
public:
    virtual void setPrice(double p) = 0;
    void setModel(int m) { model = m; }
    int getModel() { return model; }
    double getPrice() { return price; }
};

class Color : public Car {
public:
    void setPrice(double p) {
        price = p + 1000;
    }
};

class Company : public Car {
public:
    void setPrice(double p) {
        price = p + 2000;
    }
};

int main() {
    Color c;
    c.setModel(1);
    c.setPrice(5000);
    cout << c.getModel() << " " << c.getPrice() << "\n";

    Company cmp;
    cmp.setModel(2);
    cmp.setPrice(6000);
    cout << cmp.getModel() << " " << cmp.getPrice() << "\n";
}
