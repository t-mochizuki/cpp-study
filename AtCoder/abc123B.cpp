#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    const int N = 5;
    vector<int> v;
    REP(0, i, N) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    vector<int> w;
    do {
        int tmp = 0;
        REP(0, i, N) {
            tmp += v[i];
            if (i != N - 1) {
                tmp += 9;
                tmp /= 10;
                tmp *= 10;
            }
        }
        w.push_back(tmp);
    } while(next_permutation(v.begin(), v.end()));

    sort(w.begin(), w.end());

    cout << w[0] << endl;

    return 0;
}
