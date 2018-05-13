#include <stdio.h>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i <= n; ++i)

map<int, vector<int> > memo2;

// 約数
void divisor(int n) {
    map<int, vector<int> >::iterator it2 = memo2.find(n);
    if (it2 != memo2.end()) return ;
    else {
        memo2.insert(make_pair(n, 0));
        it2 = memo2.find(n);
    }


    map<int, int> m;

    int a = 2;
    while (n >= a * a) {
        if (n % a == 0) {
            // printf("%ld * ", a);
            n /= a;
            map<int, int>::iterator it = m.find(a);
            if (it != m.end()) {
                m[a]++;
            } else {
                m.insert(make_pair(a, 1));
            }
        } else {
            a++;
        }
    }
    // printf("%ld\n", n);
    map<int, int>::iterator it = m.find(n);
    if (it != m.end()) {
        m[n]++;
    } else {
        m.insert(make_pair(n, 1));
    }

    // printf("keys\n");
    for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        // if (it == m.begin()) printf("%d", it->first);
        // else printf(", %d", it->first);
        it2->second.push_back(it->first);
    }
    // printf("\n");

    m.clear();
}

bool isReducible(int n, vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        if (n % *it == 0) return true;
    }
    return false;
}

long D(long n) {
    divisor(n);

    long cnt = 0;
    REP(1, i, n - 1) {
        if (isReducible(i, memo2.find(n)->second)) {
            // printf("Reducible: %d/%ld\n", i, n);
        } else {
            // printf("Irreducible: %d/%ld\n", i, n);
            cnt++;
        }
    }

    return cnt;
}

int main() {
    const int MAX_N = 1e6 + 1;
    int memo[MAX_N] = {0};

    int t; // 1e4
    scanf("%d", &t);

    REP(1, i, t) {
        int N; // 1e6
        scanf("%d", &N);

        long Fn = 0;
        REP(2, i, N) {
            if (memo[i] == 0) memo[i] = D(i);
            Fn += memo[i];
        }

        printf("%ld\n", 2 + Fn);
    }

    return 0;
}
