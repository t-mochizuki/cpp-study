#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

// TODO: メモ化

const long p = 1000000007;

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return (base * pow(base, exponent - 1)) % p;
    } else {
        T tmp = pow(base, exponent / 2);
        return (tmp * tmp) % p;
    }
}

long memo[1000005];

// n!/r!(n - r)!
long combination(long n, long r) {
    long ret = 1;
    long tmp = n;
    for (int i = 0; i < r; ++i) {
        ret *= tmp;
        ret %= p;
        tmp--;
    }

    tmp = r;
    for (int i = 0; i < r; ++i) {
        // Fermat's little theorem
        // a^p=a(mod p)
        // a^(p-2)=a^-1(mod p)
        if (memo[tmp] > p) {
            memo[tmp] = pow(tmp, p - 2);
        }
        ret *= memo[tmp];
        ret %= p;
        tmp--;
    }

    return ret;
}

void solve() {
    long k; cin >> k;
    string s; cin >> s;
    long n = s.length();

    for (int i = 0; i < 1000005; ++i) {
        memo[i] = p;
    }

    long ans = 0;
    for (long a = 0; a <= k; ++a) {
        // sの最後の文字に着目する。
        // sの最後の文字以外を配置できる組み合わせは何通りか？
        ans += (pow(25L,k-a)*pow(26L,a)%p)*combination(n-1+k-a,n-1);
        ans %= p;
    }

    cout << ans << endl;
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
