#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool negative;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0)
            negative = false;
    }

    static bool absLess(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size())
            return a.digits.size() < b.digits.size();
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i])
                return a.digits[i] < b.digits[i];
        }
        return false;
    }

public:
    BigInteger() {
        negative = false;
        digits.push_back(0);
    }

    BigInteger(const string& s) {
        negative = false;
        digits.clear();
        int i = 0;
        if (s[0] == '-') {
            negative = true;
            i = 1;
        }
        for (int j = s.length() - 1; j >= i; --j)
            digits.push_back(s[j] - '0');
        removeLeadingZeros();
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        if (!(digits.size() == 1 && digits[0] == 0))
            result.negative = !negative;
        return result;
    }

    BigInteger operator+(const BigInteger& other) const {
        if (negative == other.negative) {
            BigInteger result;
            result.negative = negative;
            result.digits.clear();

            int carry = 0;
            for (size_t i = 0; i < digits.size() || i < other.digits.size() || carry; ++i) {
                int sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }

            result.removeLeadingZeros();
            return result;
        }

        if (negative)
            return other - (-*this);
        return *this - (-other);
    }

    BigInteger operator-(const BigInteger& other) const {
        if (negative != other.negative)
            return *this + (-other);

        if (absLess(*this, other)) {
            BigInteger result = other - *this;
            result.negative = !negative;
            return result;
        }

        BigInteger result;
        result.negative = negative;
        result.digits.clear();

        int borrow = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int sub = digits[i] - borrow;
            if (i < other.digits.size())
                sub -= other.digits[i];

            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.digits.push_back(sub);
        }

        result.removeLeadingZeros();
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return negative == other.negative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (negative != other.negative)
            return negative;

        if (digits.size() != other.digits.size())
            return negative ? digits.size() > other.digits.size() : digits.size() < other.digits.size();

        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i])
                return negative ? digits[i] > other.digits[i] : digits[i] < other.digits[i];
        }

        return false;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        if (num.negative)
            out << '-';
        for (int i = num.digits.size() - 1; i >= 0; --i)
            out << char(num.digits[i] + '0');
        return out;
    }

    friend istream& operator>>(istream& in, BigInteger& num) {
        string s;
        in >> s;
        num = BigInteger(s);
        return in;
    }
};

int main() {
    BigInteger a, b;
    cout << "Enter two big integers:\n";
    cin >> a >> b;

    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a < b: " << (a < b) << endl;

    return 0;
}
