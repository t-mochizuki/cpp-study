#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int f(int n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}

int main() {
    int s;
    cin >> s;

    vector<int> v;
    while(find(v.begin(), v.end(), s) == v.end()) {
        v.push_back(s);
        s = f(s);
    }

    cout << v.size() + 1 << endl;

    return 0;
}
