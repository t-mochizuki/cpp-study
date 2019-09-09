#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    int cnt = 0;
    vector<int> v;
    v.push_back(cnt);
    REP(1, i, S.length()) {
        if (S[i - 1] == 'A' && S[i] == 'C') {
            cnt++;
        }

        v.push_back(cnt);
    }

    int l[Q], r[Q];
    REP(0, i, Q) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }

    REP(0, i, Q) {
        int ans = v[r[i]] - v[l[i]];
        cout << ans << endl;
    }

    return 0;
}
