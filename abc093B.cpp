#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B, K;
    scanf("%d %d %d", &A, &B, &K);

    vector<int> v;
    REP(A, i, min(A + K, B + 1)) {
        v.push_back(i);
    }

    REP(max(A, B - K + 1), i, B + 1) {
        v.push_back(i);
    }

    sort(v.begin(), v.end());
    vector<int>::iterator it = unique(v.begin(), v.end());
    v.erase(it, v.end());

    for (it = v.begin(); it != v.end(); ++it) {
        printf("%d\n", *it);
    }

    return 0;
}
