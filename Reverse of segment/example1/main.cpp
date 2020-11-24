#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

template<class T> inline void swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

// A[0, N)を反転する
inline void reverse(int N, int A[]) {
    for (int i = 0; i < N / 2; ++i) {
        int j = N - i - 1;
        swap(A[i], A[j]);
    }
}

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    reverse(n, a);

    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            cout << a[i] << endl;
        } else {
            cout << a[i] << " ";
        }
    }
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
