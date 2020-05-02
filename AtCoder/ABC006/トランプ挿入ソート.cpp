#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::lower_bound;

int main() {
    int n; cin >> n;
    int c[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        vector<int>::iterator it2 = lower_bound(v.begin(), v.end(), c[i]);
        if (it2 == v.end()) {
            v.push_back(c[i]);
        } else {
            (*it2) = c[i];
        }

        // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        //     if (it == v.begin()) {
        //         cout << (*it);
        //     } else {
        //         cout << ", " << (*it);
        //     }
        // }
        // cout << endl;

    }

    cout << n - v.size() << endl;

    return 0;
}
