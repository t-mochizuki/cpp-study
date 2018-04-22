#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {

    int n;
    scanf("%d", &n);

    int a[n];
    REP(i, n) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);
    int m = a[n - 1];
    int r = m / 2;

    vector<pair<int, int> > v;
    REP(i, n) {
        v.push_back(make_pair((r < a[i]) ? m - a[i] : a[i], a[i]));
    }

    sort(v.begin(), v.end(), greater<pair<int, int> >());

    printf("%d %d\n", m, (m == v[0].second) ? v[1].second : v[0].second);

    return 0;
}
