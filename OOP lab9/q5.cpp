#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
private:
    double w, h;
public:
    Rectangle(double x, double y) {
        w = x;
        h = y;
    }

    double getArea() {
        return w * h;
    }
};

class Triangle : public Shape {
private:
    double b, h;
public:
    Triangle(double x, double y) {
        b = x;
        h = y;
    }

    double getArea() {
        return 0.5 * b * h;
    }
};

int main() {
    Rectangle r(10, 5);
    Triangle t(8, 4);
    cout << r.getArea() << "\n";
    cout << t.getArea() << "\n";
}
