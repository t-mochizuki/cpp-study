#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct data_t {
    int I;
    int X;
    int M;
};

bool fx(data_t a, data_t b) {
    return a.X < b.X;
}

bool fi(data_t a, data_t b) {
    return a.I < b.I;
}

int main() {
    int N;
    scanf("%d", &N);

    vector<data_t> v;
    int x;
    REP(0, i, N) {
        scanf("%d", &x);
        v.push_back((struct data_t){i, x, 0});
    }

    // sort by X
    sort(v.begin(), v.end(), fx);

    // REP(0, i, N) {
    //     printf("I=%d, X=%d, M=%d\n", v[i].I, v[i].X, v[i].M);
    // }

    REP(0, i, N) {
        if (i < N / 2) {
            v[i].M = v[N / 2].X;
        } else {
            v[i].M = v[N / 2 - 1].X;
        }
    }

    // sort by I
    sort(v.begin(), v.end(), fi);

    // REP(0, i, N) {
    //     printf("I=%d, X=%d, M=%d\n", v[i].I, v[i].X, v[i].M);
    // }

    REP(0, i, N) {
        printf("%d\n", v[i].M);
    }

    return 0;
}
