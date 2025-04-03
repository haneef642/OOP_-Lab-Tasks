#include <iostream>
using namespace std;

class Shape {
protected:
    string color;
    int position;

public:

    Shape(string col, int pos) : color(col), position(pos) {}
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {

    double radius;
public:

    Circle(string col, int pos, double r) : Shape(col, pos), radius(r) {}

    void draw() override { cout << "Drawing Circle\n"; }

    double calculateArea() override { return 3.14 * radius * radius; }
    double calculatePerimeter() override { return 2 * 3.14 * radius; }
};

class Rectangle : public Shape {

    double width, height;
public:
    Rectangle(string col, int pos, double w, double h) : Shape(col, pos), width(w), height(h) {}

    void draw() override { cout << "Drawing Rectangle"; }

    double calculateArea() override { return width * height; }
    double calculatePerimeter() override { return 2 * (width + height); }
};

int main() {


    Circle c("Red", 10, 5);
    Rectangle r("Blue", 20, 4, 6);
    c.draw();
    r.draw();
    cout << "Circle Area: " << c.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << endl;
    
}
