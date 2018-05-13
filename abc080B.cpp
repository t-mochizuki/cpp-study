#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

#define rep(a, i, n) for (int i = a; i <= n; ++i)

int f(int X) {
    int v = 0;
    while (true) {
        if (X == 0) return v;
        v += X % 10;
        X /= 10;
    }
}

bool isHarshad(int X) {
    return (X % f(X) == 0);
}

int main() {
    int N; // 1e8
    scanf("%d", &N);

    if (isHarshad(N)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
