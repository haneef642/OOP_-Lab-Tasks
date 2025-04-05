#include <iostream>
using namespace std;

class Shape {
private:
    double area;

public:
    Shape(double a = 0) {
        area = a;
    }

    double Area() const {
        return area;
    }

    Shape operator+(const Shape& other) {
        return Shape(this->area + other.area);
    }

    void display() const {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1(25.5), shape2(10.5);

    cout << "Shape 1: ";
    shape1.display();
    
    cout << "Shape 2: ";
    shape2.display();

    Shape shape3 = shape1 + shape2;

    cout << "Combined area of shape1 and shape2: ";
    shape3.display();

    return 0;
}
