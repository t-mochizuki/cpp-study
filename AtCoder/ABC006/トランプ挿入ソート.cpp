#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::less;
using std::upper_bound;

int dfs(int pos, int fin, int c[], vector<int> v) {
    if (pos == fin) {
        return v.size();
    }

    v.push_back(c[pos]);
    if (is_sorted(v.begin(), v.end(), less<int>())) {
        return dfs(pos + 1, fin, c, v);
    } else {
        v.pop_back();
        vector<int>::iterator it2 = upper_bound(v.begin(), v.end(), c[pos]);
        (*it2) = c[pos];

        // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        //     if (it == v.begin()) {
        //         cout << (*it);
        //     } else {
        //         cout << ", " << (*it);
        //     }
        // }
        // cout << endl;

        return dfs(pos + 1, fin, c, v);
    }
}

int main() {
    int n; cin >> n;
    int c[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    vector<int> v;
    cout << n - dfs(1, n + 1, c, v) << endl;

    return 0;
}
