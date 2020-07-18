#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

int interval(int x) {
    if (x == 0) {
        return 0;
    } else if (x > 0) {
        return 1;
    } else {
        return 2;
    }
}

int search(int cur, int seq[], int depth, int A[]) {
    if (cur == depth) {

        // for (int i = 0; i < depth; ++i) {
        //     cout << seq[i];
        // }
        // cout << endl;

        int count = 0;

        for (int i = 1; i < depth; ++i) {
            if (interval(seq[i] - seq[i - 1]) != interval(A[i] - A[i - 1])) {
                count++;
            }
        }

        return count;
    }

    seq[cur] = 0;
    int a = search(cur + 1, seq, depth, A);
    seq[cur] = 1;
    int b = search(cur + 1, seq, depth, A);
    seq[cur] = 2;
    int c = search(cur + 1, seq, depth, A);
    seq[cur] = 3;
    int d = search(cur + 1, seq, depth, A);

    return min(a, min(b, min(c, d)));
}

void solve(int x) {
    int K; cin >> K;
    int A[K];
    for (int i = 0; i < K; ++i) {
        cin >> A[i];
    }

    if (K > 10) {
        terminate();
    }

    int seq[K];
    int count = search(0, seq, K, A);

    cout << "Case #" << x << ": " << count << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("KickStart/Round D 2020/Alien Piano.input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#endif

    return 0;
}
