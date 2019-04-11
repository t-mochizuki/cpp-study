#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;


    vector<int> v, w;
    REP(0, i, M) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            v.push_back(b);
        } else if (b == 1) {
            v.push_back(a);
        } if (a == N) {
            w.push_back(b);
        } else if (b == N) {
            w.push_back(a);
        }
    }

    REP(0, i, v.size()) {
        REP(0, j, w.size()) {
            if (v[i] == w[j]) {
                // cout << "v[i]=" << v[i] << endl;
                // cout << "w[j]=" << w[j] << endl;
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
