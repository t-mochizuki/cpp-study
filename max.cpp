#include <stdio.h>
#include <iostream>
#include <cstdarg>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int func(const int N, const int argv...) {
    va_list xs; va_start(xs, argv); int x = argv;
    REP(1, i, N) {
        int y = va_arg(xs, int);
        if (x < y) {
            x = y;
        }
    }

    va_end(xs);

    return x;
}

int main() {
    cout << func(1, 3) << endl;
    cout << func(2, 1, -1) << endl;
    cout << func(3, 4, 1, -1) << endl;
    cout << func(5, -2, 7, 6, 1, -1) << endl;

    return 0;
}
