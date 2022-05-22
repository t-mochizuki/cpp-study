#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include "BigInteger.h"

#define rep(i, a, n) for (long i = (a); i < (n); ++i)

BigInteger BigInteger::subtract(const BigInteger& o) const {
    std::vector<int> u;
    u.resize(n);

    int c = 0;
    rep(i, 0, n) {
        int x = 0;
        if (i < o.v.size()) {
            x = v[i]-o.v[i]+c;
        } else {
            x = v[i]+c;
        }

        if (x < 0) {
            x += 10;
            c = -1;
        } else {
            c = 0;
        }
        u[i] = x;
    }

    while (u.size() >= 2 and u[u.size()-1] == 0) {
        u.pop_back();
    }

    return BigInteger(u);
}

BigInteger BigInteger::add(const BigInteger& o) const {
    bool sign = false;
    if (minus and o.minus) {
        sign = true;
    } else if (not minus and not o.minus) {
        sign = false;
    } else {
    }

    std::vector<int> u;
    u.resize(n+1);

    int c = 0;
    rep(i, 0, n) {
        int x = 0;
        if (i < o.v.size()) {
            x = v[i]+o.v[i]+c;
        } else {
            x = v[i]+c;
        }
        c = x / 10;
        u[i] = x % 10;
    }

    if (c != 0) {
        u[n] = c;
    } else {
        u.resize(n);
    }

    return BigInteger(u, sign);
}

BigInteger BigInteger::multiply(int j, const BigInteger& o) const {
    std::vector<int> u;
    u.resize(n+1+j);

    int c = 0;
    rep(i, 0, n) {
        int x = 0;
        x = v[i]*o.v[j]+c;
        c = x / 10;
        u[i+j] = x % 10;
    }

    if (c != 0) {
        u[n+j] = c;
    } else {
        u.resize(n+j);
    }

    return BigInteger(u);
}

BigInteger BigInteger::multiply(const BigInteger& o) const {
    bool sign = false;
    if ((minus and o.minus) or (not minus and not o.minus)) {
        sign = false;
    } else {
        sign = true;
    }

    auto p = BigInteger("0");
    rep(i, 0, o.v.size()) {
        auto q = multiply(i, o);
        p = q.add(p);
    }

    p.minus = sign;

    while (p.n >= 2 and p.v[p.n-1] == 0) {
        p.v.pop_back();
        p.n--;
    }

    return p;
}

BigInteger BigInteger::divide(const BigInteger& divisor) const {
    bool sign = false;
    if ((minus and divisor.minus) or (not minus and not divisor.minus)) {
        sign = false;
    } else {
        sign = true;
    }

    if (divisor > *this) {
        auto obj = BigInteger("0");
        return obj;
    }

    if (*this == divisor) {
        auto obj = BigInteger("1");
        obj.minus = sign;
        return obj;
    }

    auto p = BigInteger("0");
    int i = n-1;
    while (i > 0) {
        auto obj = p.multiply(BigInteger("10"));
        obj = obj.add(BigInteger(std::to_string(v[i])));
        obj.resize(divisor);
        if ((obj > divisor) or (obj == divisor)) {
            break;
        }
        p = obj;
        i--;
    }

    std::string s;
    for (; i >= 0; --i) {
        p = p.multiply(BigInteger("10"));
        p = p.add(BigInteger(std::to_string(v[i])));
        int c = 9;
        auto obj = BigInteger("0");
        while (c > 0) {
            obj = BigInteger(std::to_string(c)).multiply(divisor);
            p.resize(obj);
            obj.resize(p);
            if ((p > obj) or (p == obj)) {
                break;
            }
            c--;
        }
        p = p.subtract(BigInteger(std::to_string(c)).multiply(divisor));
        s.append(std::to_string(c));
    }

    auto q = BigInteger(s);
    if (not (q == BigInteger("0"))) {
        q.minus = sign;
    }

    return q;
}
