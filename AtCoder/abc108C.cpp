#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v;
    vector<int> w;
    REP(1, i, N + 1) {
        if (K % 2 == 0) {
            if (i % K == K / 2) {
                v.push_back(i);
            }
            if (i % K == 0) {
                w.push_back(i);
            }
        } else {
            if (i % K == 0) {
                v.push_back(i);
            }
        }
    }

    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    //     cout << *it << endl;
    // }

    long len1 = v.size();
    long len2 = w.size();
    cout << len1 * len1 * len1 + len2 * len2 * len2 << endl;

    return 0;
}
