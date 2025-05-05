#include <iostream>
#include <any>
#include <stdexcept>
using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Type mismatch";
    }
};

class TypeSafeContainer {
    any data;
public:
    template<typename T>
    void store(const T& value) {
        data = value;
    }

    template<typename T>
    T get() {
        if (!data.has_value() || data.type() != typeid(T))
            throw BadTypeException();
        return any_cast<T>(data);
    }
};
