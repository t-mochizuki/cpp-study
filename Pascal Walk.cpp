#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct data_t {
    int r;
    int k;
};

int pow(int x, int n) {
    return n == 0 ? 1 : x * pow(x, n - 1);
}

int main() {
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        // input
        int n; cin >> n;

        vector<data_t> v;
        if (n <= 30) {
            for (int i = 1; i <= n; ++i) {
                v.push_back((data_t){i, 1});
            }
        } else {
            n -= 30;

            int b[32];
            REP(0, i, 32) {
                b[i] = ((n >> i) & 0x1);
            }

            bool isLeft = true;
            for (int r = 1; r <= 30; ++r) {
                if (b[r - 1] == 0) {
                    if (isLeft) {
                        v.push_back((data_t){r, 1});
                    } else {
                        v.push_back((data_t){r, r});
                    }
                    n -= 1;
                } else {
                    // 2 ^ (r - 1)
                    if (isLeft) {
                        for (int c = 1; c <= r; ++c) {
                            v.push_back((data_t){r, c});
                        }
                    } else {
                        for (int c = r; c >= 1; --c) {
                            v.push_back((data_t){r, c});
                        }
                    }
                    isLeft = !isLeft;
                    n -= pow(2, r - 1);
                }
            }

            n += 30;
            if (n > 0) {
                if (isLeft) {
                    for (int r = 31; n != 0; ++r) {
                        v.push_back((data_t){r, 1});
                        n--;
                    }
                } else {
                    for (int r = 31; n != 0; ++r) {
                        v.push_back((data_t){r, r});
                        n--;
                    }
                }
            }
        }

        // output
        cout << "Case #" << x << ":" << endl;
        for (vector<data_t>::iterator it = v.begin(); it != v.end(); ++it) {
            cout << it->r << " " << it->k << endl;
        }
    }
    return 0;
}
