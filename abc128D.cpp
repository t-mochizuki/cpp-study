#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, K; cin >> N >> K;

    deque<int> d;
    REP(0, n, N) {
        int tmp; cin >> tmp;
        d.push_back(tmp);
    }

    // for(deque<int>::iterator it = d.begin(); it != d.end(); ++it) {
    //     cout << (*it) << endl;
    // }

    vector<int> v;
    for (int A = 0; A <= min(N, K); ++A) {
        for (int B = 0; B <= min(N, K) - A; ++ B) {
            // cout << A << ", " << B << endl;
            priority_queue<int, vector<int>, greater<int> > q;
            for (deque<int>::iterator it = d.begin(); it != d.begin() + A; ++it) {
                q.push(*it);
            }

            for (deque<int>::reverse_iterator it = d.rbegin(); it != d.rbegin() + B; ++it) {
                q.push(*it);
            }

            // while (!q.empty()) {
            //     cout << q.top() << endl;
            //     q.pop();
            // }

            int L = K - (A + B);
            int l = 0;
            // cout << "L: " << L << endl;
            while (!q.empty() && l < L) {
                int t = q.top();
                if (t > 0) {
                    break;
                } else {
                    q.pop();
                }
                l++;
            }

            int cnt = 0;
            while (!q.empty()) {
                cnt += q.top();
                q.pop();
            }

            v.push_back(cnt);
        }
    }

    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    //     cout << (*it) << endl;
    // }

    cout << *max_element(v.begin(), v.end()) << endl;

    return 0;
}
