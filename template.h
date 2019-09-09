#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

#define RREP(a, i, n) for (int i = n - 1; i >= a; --i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int abs(int X, int Y) {
    return X > Y ? X - Y : Y - X;
}

float abs(float X, float Y) {
    return X > Y ? X - Y : Y - X;
}

void swap(int &A, int &B) {
    int T = A;
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

int gcd(int m, int n) {
  while (n > 0) {
    int r = m % n;
    m = n;
    n = r;
  }

  return m;
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
