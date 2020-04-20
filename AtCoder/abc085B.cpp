#include <stdio.h>
#include <set>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    set<int> d;
    REP(i, N) {
        int j = 0;
        scanf("%d", &j);
        d.insert(j);
    }

    printf("%lu\n", d.size());
    return 0;
}

