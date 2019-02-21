#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct range_t {
    int a, b;
};

int main() {
    int n;
    cin >> n;

    range_t r[n];
    REP(0, i, n) {
        int a, b;
        cin >> a >> b;
        r[i] = (range_t){a, b};
    }

    int c[1000002];
    REP(0, i, 1000002) {
        c[i] = 0;
    }

    REP(0, i, n) {
        c[r[i].a]++;
        c[r[i].b + 1]--;
    }

    REP(0, i, 1000002) {
        if (i != 0) {
            c[i] += c[i - 1];
        }
    }

    sort(c, c + 1000002);

    cout << c[1000001] << endl;

    return 0;
}
