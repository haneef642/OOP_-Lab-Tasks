#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "ArrayIndexOutOfBounds";
    }
};

template<typename T>
class SafeArray {
    T* arr;
    int size;
public:
    SafeArray(int s) : size(s) {
        arr = new T[size];
    }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw ArrayIndexOutOfBounds();
        return arr[index];
    }

    ~SafeArray() {
        delete[] arr;
    }
};

int main() {
    SafeArray<int> a(3);
    try {
        a[0] = 5;
        a[3] = 10;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
