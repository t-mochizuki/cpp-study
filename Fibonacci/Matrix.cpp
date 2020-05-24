#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

#define LL unsigned long long

void multiplyBy(LL *M1, LL *M2) {
    LL T[4] = {0};
    T[0]=M1[0]*M2[0]+M1[1]*M2[2];
    T[1]=M1[0]*M2[1]+M1[1]*M2[3];
    T[2]=M1[2]*M2[0]+M1[3]*M2[2];
    T[3]=M1[2]*M2[1]+M1[3]*M2[3];

    for (int i = 0; i < 4; ++i) {
        M1[i] = T[i];
    }
}

void calc(int N, LL *M) {
    if (N != 1) {
        multiplyBy(M, M);
        calc(N / 2, M);
    }
}

void unitMatrix(int N, LL *M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            M[i + N * j] = i == j ? 1 : 0;
        }
    }
}

void solve() {
    int N; cin >> N;

    LL R[4] = {0};
    unitMatrix(2, R);

    // 2進数で表す
    vector<int> v;
    for (int i = 0; i < 32; ++i) {
        if (((N >> i) & 0x1) == 0x1) {
            v.push_back(0x1 << i);
        }
    }

    for (decltype(v)::iterator it = v.begin(); it != v.end(); ++it) {
        // cout << (*it) << endl;
        LL M[4] = {1,1,1,0};
        if (*it == 1) {
            multiplyBy(R, M);
        } else {
            calc(*it, M);
            multiplyBy(R, M);
        }
    }

    // for (int i = 0; i < 4; ++i) {
    //     printf("R[%d]=%lld\n", i, R[i]);
    // }

    cout << R[2] << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("Fibonacci/Matrix.input");
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
