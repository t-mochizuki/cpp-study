#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

#define rep(i, a, n) for (long i = (a); i < (n); ++i)

class BigInteger {
private:

public:

    int n;

    std::vector<int> v;

    bool minus = false;

    BigInteger(std::string s) {
        if (s[0] == '-') {
            minus = true;
            s = s.substr(1);
        }

        n = s.size();
        v.resize(n);
        rep(i, 0, n) {
            v[n-1-i] = s[i]-'0';
        }
    }

    BigInteger(std::vector<int> a, bool sign = false) {
        v = a;
        n = a.size();
        minus = sign;
    }

    bool operator==(const BigInteger& o) const {
        bool ok = true;
        rep(i, 0, n) {
            if (v[i] != o.v[i]) {
                ok = false;
                break;
            }
        }
        return ok;
    }

    bool operator>(const BigInteger& o) const {
        bool ok = false;
        rep(i, 0, n) {
            if (v[n-i-1] == o.v[n-i-1]) {
                continue;
            }
            if (v[n-i-1] > o.v[n-i-1]) {
                ok = true;
            }
            break;
        }
        return ok;
    }

    BigInteger subtract(const BigInteger& o) const;

    BigInteger add(const BigInteger& o) const;

    BigInteger multiply(int j, const BigInteger& o) const;

    BigInteger multiply(const BigInteger& o) const;

    BigInteger divide(const BigInteger& o) const;

    std::string toString() const {
        std::string s;
        if (minus) {
            s.append("-");
        }
        for (int i = n-1; i >= 0; --i) {
            s.append(std::to_string(v[i]));
        }
        return s;
    };

    void resize(const BigInteger& o) {
        while (n < o.v.size()) {
            v.push_back(0);
            n++;
        }
    }
};
