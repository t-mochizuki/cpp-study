#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    long N; cin >> N;

    vector<long> v;
    REP(0, i, 5) {
        long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cout << 5 + (N % v[0] == 0 ? N / v[0] - 1 : N / v[0]) << endl;

    return 0;
}
