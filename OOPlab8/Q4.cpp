#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) {
        value = v;
    }

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(8);

    cout << "Original: ";
    num.display();

    --num;
    cout << "After prefix -- (multiply by 4): ";
    num.display();

    num--;
    cout << "After postfix -- (divide by 4): ";
    num.display();

    return 0;
}
