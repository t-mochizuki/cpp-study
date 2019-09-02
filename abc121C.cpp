#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    long N, M;
    cin >> N >> M;

    long A, B;
    priority_queue<pair<long, long>, vector<pair<long, long> >, greater<pair<long, long> > > que;
    REP(0, i, N) {
        cin >> A >> B;
        que.push(make_pair(A, B));
    }

    long ans = 0;
    REP(0, i, N) {
        pair<long, long> p = que.top(); que.pop();

        if (M > p.second) {
            ans += p.first * p.second;
            M -= p.second;
        } else {
            ans += p.first * M;
            M = 0;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
