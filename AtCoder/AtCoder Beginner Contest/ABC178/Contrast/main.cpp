#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    int n; cin >> n;
    int a[n], b[n], c[200001];
    for (int i = 0; i <= 20000; ++i) {
        c[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        c[b[i]]++;
    }

    bool pigeon = false;
    for (int i = 0; i <= 20000; ++i) {
        if (c[i] > n) {
            pigeon = true;
            break;
        }
    }

    if (pigeon) {
        cout << "No" << endl;
    } else {

        for (int j = 0; j < n; ++j) {
            bool all = true;
            for (int i = 0; i < n; ++i) {
                if (a[i] == b[(i+j)%n]) {
                    all = false;
                    break;
                }
            }

            if (all) {
                cout << "Yes" << endl;
                for (int i = 0; i < n; ++i) {
                    if (i == n - 1) {
                        cout << b[(i+j)%n] << endl;
                    } else {
                        cout << b[(i+j)%n] << " ";
                    }
                }
                break;
            }
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
