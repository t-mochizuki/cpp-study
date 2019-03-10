#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct data_t {
    int takahashi;
    int aoki;
    int takahashi_sum;
    int aoki_sum;
};

#define REP(a, i, n) for (int i = a; i < n; ++i)

int takahashi_calc(int* a, int s, int e) {
    int sum = 0;
    for (int i = s; i <= e; i += 2) {
        sum += a[i];
    }
    return sum;
}

int aoki_calc(int* a, int s, int e) {
    int sum = 0;
    for (int i = s + 1; i <= e; i += 2) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    int a[N];
    REP(0, i, N) {
        cin >> a[i];
    }

    vector<data_t> v;
    REP(0, takahashi, N) {
        REP(takahashi, aoki, N) {
            if (takahashi == aoki) {
                continue;
            }
            v.push_back((data_t){takahashi, aoki, takahashi_calc(a, takahashi, aoki), aoki_calc(a, takahashi, aoki)});
        }
    }

    int ans = 0;
    int max_aoki = -51;
    for (vector<data_t>::iterator it = v.begin(); it != v.end(); ++it) {
        if (it->takahashi_sum > it->aoki_sum) {
            if (it->aoki_sum > max_aoki) {
                max_aoki = it->aoki_sum;
                ans = it->takahashi_sum;
            }
            // printf("%d %d %d %d\n", it->takahashi, it->aoki, it->takahashi_sum, it->aoki_sum);
        }
    }

    printf("%d\n", ans);

    return 0;
}
