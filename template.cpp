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

int abs(int a, int b) {
    return max(b - a, a - b);
}

int main() {
    return 0;
}
