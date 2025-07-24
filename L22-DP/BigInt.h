#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

class BigInt {
private:
    static const int BASE = 1000000000;
    static const int WIDTH = 9;
    std::vector<int> digits;
    bool negative;

    void trim() {
        while (!digits.empty() && digits.back() == 0)
            digits.pop_back();
        if (digits.empty()) negative = false;
    }

public:
    BigInt(long long num = 0) {
        if (num < 0) {
            negative = true;
            num = -num;
        } else {
            negative = false;
        }

        do {
            digits.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
    }

    BigInt(const std::string& s) {
        negative = false;
        digits.clear();
        std::string str = s;
        if (str[0] == '-') {
            negative = true;
            str = str.substr(1);
        }
        for (int i = (int)str.length(); i > 0; i -= WIDTH) {
            int end = i;
            int start = std::max(0, i - WIDTH);
            digits.push_back(std::stoi(str.substr(start, end - start)));
        }
        trim();
    }

    friend std::ostream& operator<<(std::ostream& out, const BigInt& x) {
        if (x.negative && !x.isZero()) out << '-';
        if (x.digits.empty()) {
            out << 0;
        } else {
            out << x.digits.back();
            for (int i = (int)x.digits.size() - 2; i >= 0; --i)
                out << std::setw(WIDTH) << std::setfill('0') << x.digits[i];
        }
        return out;
    }

    bool isZero() const {
        return digits.empty();
    }

    BigInt operator+(const BigInt& b) const {
        if (negative == b.negative) {
            BigInt res;
            res.negative = negative;
            res.digits.clear();
            int carry = 0;
            for (size_t i = 0; i < std::max(digits.size(), b.digits.size()) || carry; ++i) {
                int sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < b.digits.size()) sum += b.digits[i];
                res.digits.push_back(sum % BASE);
                carry = sum / BASE;
            }
            return res;
        } else {
            return *this - (-b);
        }
    }

    BigInt operator-() const {
        BigInt res = *this;
        if (!res.isZero()) res.negative = !negative;
        return res;
    }

    BigInt operator-(const BigInt& b) const {
        if (negative != b.negative) {
            return *this + (-b);
        }

        if (absLess(*this, b)) {
            BigInt res = b - *this;
            res.negative = !negative;
            return res;
        }

        BigInt res;
        res.negative = negative;
        res.digits.clear();
        int carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int sub = digits[i] - carry;
            if (i < b.digits.size()) sub -= b.digits[i];
            if (sub < 0) {
                sub += BASE;
                carry = 1;
            } else {
                carry = 0;
            }
            res.digits.push_back(sub);
        }
        res.trim();
        return res;
    }

    BigInt operator*(const BigInt& b) const {
        BigInt res;
        res.negative = negative != b.negative;
        res.digits = std::vector<int>(digits.size() + b.digits.size(), 0);

        for (size_t i = 0; i < digits.size(); ++i) {
            long long carry = 0;
            for (size_t j = 0; j < b.digits.size() || carry; ++j) {
                long long cur = res.digits[i + j] + carry +
                                1LL * digits[i] * (j < b.digits.size() ? b.digits[j] : 0);
                res.digits[i + j] = cur % BASE;
                carry = cur / BASE;
            }
        }
        res.trim();
        return res;
    }

    bool operator<(const BigInt& b) const {
        if (negative != b.negative)
            return negative;

        if (digits.size() != b.digits.size())
            return (digits.size() < b.digits.size()) ^ negative;

        for (int i = (int)digits.size() - 1; i >= 0; --i) {
            if (digits[i] != b.digits[i])
                return (digits[i] < b.digits[i]) ^ negative;
        }
        return false;
    }

    bool operator==(const BigInt& b) const {
        return negative == b.negative && digits == b.digits;
    }

    bool operator!=(const BigInt& b) const {
        return !(*this == b);
    }

    bool operator>(const BigInt& b) const {
        return b < *this;
    }

    bool operator<=(const BigInt& b) const {
        return !(*this > b);
    }

    bool operator>=(const BigInt& b) const {
        return !(*this < b);
    }

private:
    static bool absLess(const BigInt& a, const BigInt& b) {
        if (a.digits.size() != b.digits.size())
            return a.digits.size() < b.digits.size();
        for (int i = (int)a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i])
                return a.digits[i] < b.digits[i];
        }
        return false;
    }
};

#endif // BIGINT_H
