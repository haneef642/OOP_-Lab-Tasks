#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    void reduce() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) {
        numerator = num;
        denominator = denom;
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1)
            os << f.numerator;
        else
            os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(2, 4), f2(3, 6);
    cout << (f1 + f2) << endl;
    return 0;
}
