#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

template<class T> inline T gcd(T a, T b) {
  while (b > 0) {
    T r = a % b;
    a = b;
    b = r;
  }

  return a;
}

template<class T> inline T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

int main() {
    long A, B; cin >> A >> B;
    cout << lcm(A, B) << endl;
    return 0;
}
