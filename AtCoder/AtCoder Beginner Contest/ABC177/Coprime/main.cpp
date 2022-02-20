#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::set;

template<class T> inline T gcd(T a, T b) {
    while (b > 0) {
      T r = a % b;
      a = b;
      b = r;
    }

    return a;
}

template<class T> inline T _gcd(int n, T* a) {
    T ret = a[0];
    for (int i = 0; i < n; ++i) {
        if (ret == 1) {
            return 1;
        } else {
            if (ret > a[i]) {
                ret = gcd(ret, a[i]);
            } else {
                ret = gcd(a[i], ret);
            }
        }
    }

    return ret;
}

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

void factorize(int A, int *D, set<int> &S) {
    if (D[A] == 0) {
        cout << endl;
    } else if (D[A] == A) {
        // cout << A << endl;
        S.insert(A);
    } else {
        // cout << D[A] << ",";
        S.insert(D[A]);
        factorize(A / D[A], D, S);
    }
}

// O(AloglogA)
void sieve(int A, int *D) {
    vector<int> a;
    a.resize(A, 1);
    a[0] = 0; a[1] = 0;

    D[0] = 0; D[1] = 1;
    for (int i = 2; i < A; ++i) {
        a[i] = 1;
        D[i] = i;
    }

    for (int i = 4; i < A; i += 2) {
        a[i] = 0;
        D[i] = 2;
    }

    for (int i = 3; i <= sqrt(A); i += 2) {
        if (a[i] == 0) {
            continue;
        }
        for (int j = i * 2; j < A; j += i) {
            a[j] = 0;
            D[j] = min(D[j], i);
        }
    }
}

void solve() {
    int n; cin >> n;
    int a[n];
    int A = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        A = max(A, a[i]);
    }

    A++;
    int D[A];
    for (int i = 0; i < A; ++i) {
        D[i] = 0;
    }
    sieve(A, D);

    int setwise = _gcd(n, a);

    if (setwise != 1) {
        cout << "not coprime" << endl;
        return ;
    }

    vector<bool> check;
    check.resize(A, false);
    bool pairwise = true;
    for (int i = 0; i < n; ++i) {
        set<int> T;
        factorize(a[i], D, T);

        for (auto v : T) {
            if (check[v] == false) {
                check[v] = true;
            } else {
                if (v != 1) {
                    pairwise = false;
                }
            }
        }

        if (pairwise == false) {
            break;
        }
    }

    if (pairwise) {
        cout << "pairwise coprime" << endl;
        return ;
    } else {
        cout << "setwise coprime" << endl;
        return ;
    }
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
