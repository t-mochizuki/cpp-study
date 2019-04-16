#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int gcd(int m, int n) {
  while (n > 0) {
    int r = m % n;
    m = n;
    n = r;
  }

  return m;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> x;
    x.push_back(X);

    int y;
    REP(0, i, N) {
        cin >> y;
        x.push_back(y);
    }

    sort(x.begin(), x.end());

    set<int> d;
    REP(1, i, N + 1) {
        d.insert(x[i] - x[i - 1]);
    }

    // for (set<int>::iterator it = d.begin(); it != d.end(); ++it) {
    //     cout << *it << endl;
    // }

    int ans = *(d.begin());
    if (d.size() != 1) {
        for (set<int>::iterator it = d.begin(); it != d.end(); ++it) {
            ans = gcd(ans, *it);
        }
    }

    cout << ans << endl;

    return 0;
}
