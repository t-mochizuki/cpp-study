#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::set;
using std::find;

// I got WA.
void solve() {
    int n; long k; cin >> n >> k;
    int a[n + 1]; a[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }

    // for (auto x : a) {
    //     cout << x << endl;
    // }

    vector<int> v; v.push_back(1);
    set<int> s; s.insert(1);
    int tmp = a[1];
    while (s.find(tmp) == s.end()) {
        v.push_back(tmp);
        s.insert(tmp);
        tmp = a[tmp];
    }

    // for (auto x : v) {
    //     cout << x << endl;
    // }

    if (tmp == 1) {
        cout << v[k % v.size()] << endl;
    } else {
        long d = *find(v.begin(), v.end(), tmp);
        if (k <= d) {
            cout << v[k] << endl;
        } else {
            k = k - d;
            cout << v[d + k % (v.size() - d)] << endl;
        }
    }

}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
