#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int N; // プレゼントを作る機械が N 台, 1e5
int K; // プレゼント K 個, 1e5

int main() {
    scanf("%d %d", &N, &K);

    int a[N];
    int b[N];
    priority_queue<pair<long, int>, vector<pair<long, int> >, greater<pair<long, int> > > q;
    REP(i, N) {
        scanf("%d %d", &a[i], &b[i]);
        q.push(make_pair(a[i], b[i]));
    }

    long T = 0;
    int k = 0;
    while (k < K) {
        pair<long, int> p = q.top();
        T += p.first;
        k++;
        q.pop();
        q.push(make_pair(p.first + p.second, p.second));
    }

    printf("%ld\n", T);

    return 0;
}
