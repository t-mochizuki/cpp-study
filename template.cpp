#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

#define RREP(a, i, n) for (int i = n - 1; i >= 0; --i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int abs(int X, int Y) {
    return X > Y ? X - Y : Y - X;
}

void swap(int &A, int &B) {
    int T = A;
    A = B;
    B = T;
}

int main() {
    return 0;
}
