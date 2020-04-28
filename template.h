#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

#define RREP(a, i, n) for (int i = n - 1; i >= a; --i)

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline void swap(T &A, T &B) {
    T T = A;
    A = B;
    B = T;
}

int median(int* A, int n) {
    if (n % 2 == 1) {
        return A[(n + 1) / 2 - 1];
    } else {
        return (A[n / 2 - 1] + A[n / 2]) / 2;
    }
}

// greatest common divisor
template<class T> inline T gcd(T a, T b) {
  while (b > 0) {
    T r = a % b;
    a = b;
    b = r;
  }

  return a;
}

// least common multiple
// gcd(a, b) * lcm(a, b) == a * b
template<class T> inline T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

int factorial(int X) {
    int Y = 1;
    REP(1, i, X + 1) {
        Y *= i;
    }
    return Y;
}

struct UnionFind {
    vector<int> parentOf;
    vector<long> sz;

    UnionFind(int N) {
        parentOf.resize(N);
        sz.resize(N, 1);
        REP(0, i, N) {
            parentOf[i] = i;
        }
    }

    int rootOf(int x) {
        int p = parentOf[x];
        if (p == x) {
            return p;
        } else {
            int r = rootOf(p);
            parentOf[x] = r;
            return r;
        }
    }

    bool isSame(int x, int y) {
        return rootOf(x) == rootOf(y);
    }

    bool merge(int x, int y) {
        int rx = rootOf(x);
        int ry = rootOf(y);
        if (rx == ry) {
            return false;
        } else {
            if (sz[rx] < sz[ry]) {
                swap(rx, ry);
            }

            sz[rx] += sz[ry];

            parentOf[ry] = rx;

            return true;
        }
    }

    long size(int x) {
        return sz[rootOf(x)];
    }
};

int atoi(char c) {
    return c - 48;
}

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        T tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}
