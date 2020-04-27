#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int t; cin >> t;
    for(int x = 1; x <= t; ++x) {
        int n, k; cin >> n >> k;
        if (k % n != 0) {
            if (n == 4) {
                if (k == 6) {
                    cout << "Case #" << x << ": POSSIBLE" << endl;
                    cout << "1 3 2 4" << endl;
                    cout << "3 2 4 1" << endl;
                    cout << "2 4 1 3" << endl;
                    cout << "4 1 3 2" << endl;
                } else if (k == 10) {
                    cout << "Case #" << x << ": POSSIBLE" << endl;
                    cout << "2 1 3 4" << endl;
                    cout << "1 3 4 2" << endl;
                    cout << "3 4 2 1" << endl;
                    cout << "4 2 1 3" << endl;
                } else if (k == 14) {
                    cout << "Case #" << x << ": POSSIBLE" << endl;
                    cout << "3 1 4 2" << endl;
                    cout << "1 4 2 3" << endl;
                    cout << "4 2 3 1" << endl;
                    cout << "2 3 1 4" << endl;
                } else {
                    cout << "Case #" << x << ": IMPOSSIBLE" << endl;
                }
            } else {
                cout << "Case #" << x << ": IMPOSSIBLE" << endl;
            }
        } else {
            cout << "Case #" << x << ": POSSIBLE" << endl;
            int y = k / n;
            REP(0, i, n) {
                int k = y + i;
                if (k > n) {
                    k = k % n;
                }
                REP(0, j, n) {
                    if (j == 0) {
                        cout << k;
                        if (k == 1) {
                            k = n;
                        } else {
                            k--;
                        }
                    } else {
                        cout << " " << k;
                        if (k == 1) {
                            k = n;
                        } else {
                            k--;
                        }
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
