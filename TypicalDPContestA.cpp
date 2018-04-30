#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

const int MAX_N = 100;
int p[MAX_N];
vector<int> v;

void take(int i, int sum, int end) {
    if (i == end) {
        v.push_back(sum);
        return;
    }

    take(i + 1, sum + p[i], end);

    take(i + 1, sum, end);
}

int main() {
    int N;
    scanf("%d", &N);

    REP(i, N) {
        scanf("%d", &p[i]);
    }

    take(0, 0, N);

    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    //     printf("%d, ", *it);
    // }
    // printf("\n");

    sort(v.begin(), v.end());
    vector<int>::iterator it = unique(v.begin(), v.end());

    v.erase(it, v.end());

    printf("%d\n", (int)v.size());

    return 0;
}
