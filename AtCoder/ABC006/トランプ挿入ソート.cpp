#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::less;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

int dfs(int pos, int fin, int c[], vector<int> v) {
    if (pos == fin) {

        if (is_sorted(v.begin(), v.end(), less<int>())) {

            // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
            //     if (it == v.begin()) {
            //         cout << (*it);
            //     } else {
            //         cout << ", " << (*it);
            //     }
            // }
            // cout << endl;

            return v.size();
        } else {
            return -1;
        }
    }

    int lhs = dfs(pos + 1, fin, c, v);
    v.push_back(c[pos]);
    int rhs = dfs(pos + 1, fin, c, v);

    return max(lhs, rhs);
}

int main() {
    int n; cin >> n;
    int c[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    if (n > 16) {
        terminate();
    }

    vector<int> v;
    cout << n - dfs(1, n + 1, c, v) << endl;

    return 0;
}
