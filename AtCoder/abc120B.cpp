#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

void swap(int &A, int &B) {
    int T = A;
    A = B;
    B = T;
}

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    if (A > B) {
        swap(A, B);
    }

    vector<int> v;
    REP(1, i, A + 1) {
        if (A % i == 0 && B % i == 0) {
            v.push_back(i);
        }
    }

    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    //     cout << (*it) << endl;
    // }

    printf("%d\n", v[v.size() - K]);

    return 0;
}
