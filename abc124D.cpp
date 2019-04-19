#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

/* WA */
int main() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<int> v;
    vector<char> w;
    REP(0, i, S.length()) {
        int cnt = 0;
        if (S[i] == '0') {
            while (S[i] == '0') {
                i++;
                cnt++;
            }
            v.push_back(cnt);
            w.push_back('0');
            i--;
        } else {
            while (S[i] == '1') {
                i++;
                cnt++;
            }
            v.push_back(cnt);
            w.push_back('1');
            i--;
        }
    }

    // REP(0, i, v.size()) {
    //     cout << v[i] << endl;
    // }

    int ans = 0;
    int i = 0;
    while (true) {
        if (w[i] == '0') {
            if (i + 2 * K > v.size()) {
                break;
            }

            int tmp = 0;
            REP(i, j, i + 2 * K) {
                tmp += v[j];
            }
            // cout << "0: " << tmp << endl;
            ans = max(ans, tmp);
        } else {
            if (i + 2 * K + 1 > v.size()) {
                break;
            }

            int tmp = 0;
            REP(i, j, i + 2 * K + 1) {
                tmp += v[j];
            }
            // cout << "1: " << tmp << endl;
            ans = max(ans, tmp);
        }

        i++;
    }

    cout << (ans == 0 ? S.length() : ans) << endl;

    return 0;
}
