#include <iostream>
#include <stdexcept>
using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException";
    }
};

template<typename T>
class Stack {
    T* data;
    int topIndex;
    int capacity;
public:
    Stack(int size = 10) : capacity(size), topIndex(-1) {
        data = new T[capacity];
    }

    void push(T value) {
        if (topIndex + 1 >= capacity) return;
        data[++topIndex] = value;
    }

    void pop() {
        if (topIndex < 0) throw StackUnderflowException();
        --topIndex;
    }

    T top() {
        if (topIndex < 0) throw StackUnderflowException();
        return data[topIndex];
    }

    ~Stack() {
        delete[] data;
    }
};

int main() {
    Stack<int> s;
    try {
        s.push(10);
        s.push(20);
        cout << s.top() << endl;
        s.pop();
        s.pop();
        s.pop();
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
