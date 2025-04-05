#include <iostream>
#include <vector>
using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    int evaluate(const Polynomial& p, int x);
    Polynomial derivative(const Polynomial& p);
};

class Polynomial {
private:
    vector<int> coeffs;

    void trim() {
        while (!coeffs.empty() && coeffs.back() == 0)
            coeffs.pop_back();
    }

public:
    Polynomial() {}

    Polynomial(const vector<int>& c) {
        coeffs = c;
        trim();
    }

    Polynomial operator+(const Polynomial& other) const {
        vector<int> result(max(coeffs.size(), other.coeffs.size()), 0);
        for (size_t i = 0; i < coeffs.size(); ++i)
            result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i)
            result[i] += other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<int> result(max(coeffs.size(), other.coeffs.size()), 0);
        for (size_t i = 0; i < coeffs.size(); ++i)
            result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i)
            result[i] -= other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coeffs.size() + other.coeffs.size() - 1, 0);
        for (size_t i = 0; i < coeffs.size(); ++i)
            for (size_t j = 0; j < other.coeffs.size(); ++j)
                result[i + j] += coeffs[i] * other.coeffs[j];
        return Polynomial(result);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coeffs.empty()) {
            os << "0";
            return os;
        }

        bool first = true;
        for (int i = p.coeffs.size() - 1; i >= 0; --i) {
            int c = p.coeffs[i];
            if (c == 0) continue;

            if (!first) {
                os << (c > 0 ? " + " : " - ");
                c = abs(c);
            } else {
                if (c < 0) {
                    os << "-";
                    c = -c;
                }
                first = false;
            }

            if (i == 0) os << c;
            else if (i == 1) os << (c == 1 ? "x" : to_string(c) + "x");
            else os << (c == 1 ? "x^" + to_string(i) : to_string(c) + "x^" + to_string(i));
        }

        return os;
    }

    friend class PolynomialUtils;
};

int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0;
    int power = 1;
    for (int c : p.coeffs) {
        result += c * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    if (p.coeffs.size() <= 1) return Polynomial({0});
    vector<int> deriv(p.coeffs.size() - 1);
    for (size_t i = 1; i < p.coeffs.size(); ++i)
        deriv[i - 1] = p.coeffs[i] * i;
    return Polynomial(deriv);
}

int main() {
    Polynomial p1({-1, 0, 5, 2}); // 2x^3 + 5x^2 - 1
    Polynomial p2({1, 2});        // 2x + 1

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    cout << "p1 + p2: " << (p1 + p2) << endl;
    cout << "p1 - p2: " << (p1 - p2) << endl;
    cout << "p1 * p2: " << (p1 * p2) << endl;

    PolynomialUtils utils;
    cout << "p1 evaluated at x = 2: " << utils.evaluate(p1, 2) << endl;
    cout << "Derivative of p1: " << utils.derivative(p1) << endl;

    return 0;
}
