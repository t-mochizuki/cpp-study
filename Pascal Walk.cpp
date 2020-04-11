#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct data_t {
    int r;
    int k;
};

int main() {
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int n; cin >> n;

        vector<data_t> v;
        if (n >= 500) {
            v.push_back((data_t){1, 1}); // => 1
            v.push_back((data_t){2, 1}); // => 1
            v.push_back((data_t){3, 2}); // => 2
            n -= 4;
            for (int i = 3; i <= n + 2; ++i) {
                v.push_back((data_t){i, 1});
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                v.push_back((data_t){i, 1});
            }
        }
        cout << "Case #" << x << ":" << endl;
        for (vector<data_t>::iterator it = v.begin(); it != v.end(); ++it) {
            cout << it->r << " " << it->k << endl;
        }
    }
    return 0;
}
