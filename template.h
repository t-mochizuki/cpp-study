#include <stdio.h>
#include <iostream>
#include <cassert>
#include <cmath>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::sqrt;
using std::pair;
using std::make_pair;

// #define M_PI 3.14159265358979323846 /* pi */
// #define M_PIl 3.141592653589793238462643383279502884L /* pi */

void output(int x, double ans) {
    printf("Case #%d: %.6f\n", x, ans);
}

void output(int x, int ans) {
    printf("Case #%d: %d\n", x, ans);
}

template<class T>
istream& operator>>(istream& i, vector<T>& v) {
    rep(j, 0, v.size()) i >> v[j];
    return i;
}

template<class T>
ostream& operator<<(ostream& o, vector<T>& v) {
    rep(j, 0, v.size()) {
        if (j == 0) o << v[j];
        else o << " " << v[j];
    }
    return o;
}

template<class T>
ostream& operator<<(ostream& o, priority_queue<T> que) {
    bool first = true;
    while (!que.empty()) {
        T x = que.top(); que.pop();
        if (first) {
            o << x;
            first = false;
        } else {
            o << " " << x;
        }
    }
    return o;
}

const double EPSILON = 0.000000001;

using Point = pair<double, double>;

template <class T>
bool max(T &a, const T b) {
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool min(T &a, const T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

double dot(const Point &a, const Point &b) {
    return a.first * b.first + a.second * b.second;
}

double cross(const Point &a, const Point &b) {
    return a.first * b.second - a.second * b.first;
}

int counterClockWise(const Point &a, const Point &b) {
    double z = cross(a, b);

    if (z > EPSILON) {
        // cout << "COUNTER_CLOCKWISE" << endl;
        return 1;
    }

    if (z < -EPSILON) {
        // cout << "CLOCKWISE" << endl;
        return -1;
    }

    assert(z == 0);

    if (dot(a, b) < -EPSILON) {
        // cout << "ONLINE_BACK" << endl;
        return 2;
    } else if (dot(a, a) + EPSILON < dot(b, b)) {
        // cout << "ONLINE_FRONT" << endl;
        return -2;
    } else {
        // cout << "ON_SEGMENT" << endl;
        return 0;
    }
}

bool intersection(const Point &a, const Point &b, const Point &c, const Point &d) {
    auto [x0, y0] = a;
    auto [x1, y1] = b;

    auto [x2, y2] = c;
    auto [x3, y3] = d;

    Point ab = make_pair(x1-x0, y1-y0);
    Point ac = make_pair(x2-x0, y2-y0);
    Point ad = make_pair(x3-x0, y3-y0);

    if (counterClockWise(ab, ac) * counterClockWise(ab, ad) > 0) {
        return false;
    }

    Point cd = make_pair(x3-x2, y3-y2);
    Point ca = make_pair(x0-x2, y0-y2);
    Point cb = make_pair(x1-x2, y1-y2);

    if (counterClockWise(cd, ca) * counterClockWise(cd, cb) > 0) {
        return false;
    }

    return true;
}

double distance(Point &p0, Point &p1, Point &p2, Point &p3) {
    auto& [x0, y0] = p0;
    auto& [x1, y1] = p1;

    auto& [x2, y2] = p2;
    auto& [x3, y3] = p3;

    double ret = 1000000000;
    if (intersection(p0, p1, p2, p3)) {
        ret = 0.0;
    } else {
        Point ab = make_pair(x1-x0, y1-y0);

        Point ac = make_pair(x2-x0, y2-y0);
        Point ad = make_pair(x3-x0, y3-y0);

        Point bc = make_pair(x2-x1, y2-y1);
        Point bd = make_pair(x3-x1, y3-y1);

        min(ret, sqrt(dot(ac, ac)));
        min(ret, sqrt(dot(ad, ad)));
        min(ret, sqrt(dot(bc, bc)));
        min(ret, sqrt(dot(bd, bd)));

        // 線分abに点cから垂線を引く
        double w = dot(ab, ac) / dot(ab, ab);
        Point ap = make_pair(w * ab.first, w * ab.second);

        if (w > EPSILON && dot(ab, ab) >= dot(ap, ap) + EPSILON) {
            auto pc = make_pair(ac.first-ap.first, ac.second-ap.second);
            min(ret, sqrt(dot(pc, pc)));
        }

        // 線分abに点dから垂線を引く
        w = dot(ab, ad) / dot(ab, ab);
        ap = make_pair(w * ab.first, w * ab.second);

        if (w > EPSILON && dot(ab, ab) >= dot(ap, ap) + EPSILON) {
            auto pd = make_pair(ad.first-ap.first, ad.second-ap.second);
            min(ret, sqrt(dot(pd, pd)));
        }

        // 線分cdに点aから垂線を引く
        Point cd = make_pair(x3-x2, y3-y2);
        Point ca = make_pair(x0-x2, y0-y2);
        w = dot(cd, ca) / dot(cd, cd);
        Point cp = make_pair(w * cd.first, w * cd.second);

        if (w > EPSILON && dot(cd, cd) >= dot(cp, cp) + EPSILON) {
            auto pa = make_pair(ca.first-cp.first, ca.second-cp.second);
            min(ret, sqrt(dot(pa, pa)));
        }

        // 線分cdに点bから垂線を引く
        Point cb = make_pair(x1-x2, y1-y2);
        w = dot(cd, cb) / dot(cd, cd);
        cp = make_pair(w * cd.first, w * cd.second);

        if (w > EPSILON && dot(cd, cd) >= dot(cp, cp) + EPSILON) {
            auto pb = make_pair(cb.first-cp.first, cb.second-cp.second);
            min(ret, sqrt(dot(pb, pb)));
        }
    }

    return ret;
}

template <class... Args>
void debug(Args... args) {
#ifdef DEBUG
    printf(args...);
#else
#endif
}

using Vector = pair<long, long>;

pair<double, double> projection(const Vector &a, const Vector &b) {
    auto [x, y] = b;

    if (x == 0 && y == 0) {
        return make_pair(0.0, 0.0);
    } else if (x == 0) {
        return make_pair(0.0, 1.0 * a.second);
    } else if (y == 0) {
        return make_pair(1.0 * a.first, 0.0);
    } else {
        return make_pair(
                1.0 * dot(a, b) / dot(b, b) * x,
                1.0 * dot(a, b) / dot(b, b) * y);
    }
}

pair<double, double> rejection(const Vector &a, const Vector &b) {
    auto [x, y] = projection(a, b);
    return make_pair(x - a.first, y - a.second);
}

pair<double, double> crossPoint(const Vector &a, const Vector &b, const Vector &c, const Vector &d) {
    auto [x0, y0] = a;
    auto [x1, y1] = b;
    auto [x2, y2] = c;
    auto [x3, y3] = d;

    Vector cd = make_pair(x3-x2, y3-y2);
    Vector ca = make_pair(x0-x2, y0-y2);
    Vector ab = make_pair(x1-x0, y1-y0);

    double w = 1.0 * cross(ca, cd) / cross(cd, ab);

    auto [x, y] = ab;

    return make_pair(x0 + w * x, y0 + w * y);
}

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline T manhattan(T X, T Y) {
    return abs(X) + abs(Y);
}

template<class T> inline void swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

inline reverse(int N, int A[]) {
    for (int i = 0; i < N / 2; ++i) {
        int j = N - i - 1;
        swap(A[i], A[j]);
    }
}

// greatest common divisor
template<class T> inline T gcd(T a, T b) {
  while (b > 0) {
    T r = a % b;
    a = b;
    b = r;
  }

  return a;
}

// least common multiple
// gcd(a, b) * lcm(a, b) == a * b
template<class T> inline T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        T tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

int atoi(char c) {
    return c - 48;
}

int median(int* A, int n) {
    if (n % 2 == 1) {
        return A[(n + 1) / 2 - 1];
    } else {
        return (A[n / 2 - 1] + A[n / 2]) / 2;
    }
}

// 素因数分解
template <class T>
map<T, long> factorization(T n) {
    map<T, long> m;
    for (T i = 2; i * i <= n; ++i) {
        long tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        m[i] = tmp;
    }

    if (n != 1) m[n] = 1;

    return m;
}
    if (n != 1) m[n] = 1;

    return m;
}

// 約数列挙
void divisor(long n, vector<long> &v) {
    for (long i = 1; i * i <= n; ++i) {
        if (n % i != 0) {
            // 約数でない
            continue;
        }

        v.push_back(i);

        if (i != (n/i)) {
            // 商も約数である
            v.push_back(n/i);
        }
    }
}

// 階乗
int factorial(int X) {
    int Y = 1;
    REP(1, i, X + 1) {
        Y *= i;
    }
    return Y;
}

struct UnionFind {
    vector<int> parentOf;
    vector<long> sz;

    UnionFind(int N) {
        parentOf.resize(N);
        sz.resize(N, 1);
        REP(0, i, N) {
            parentOf[i] = i;
        }
    }

    int rootOf(int x) {
        int p = parentOf[x];
        if (p == x) {
            return p;
        } else {
            int r = rootOf(p);
            parentOf[x] = r;
            return r;
        }
    }

    bool isSame(int x, int y) {
        return rootOf(x) == rootOf(y);
    }

    bool merge(int x, int y) {
        int rx = rootOf(x);
        int ry = rootOf(y);
        if (rx == ry) {
            return false;
        } else {
            if (sz[rx] < sz[ry]) {
                swap(rx, ry);
            }

            sz[rx] += sz[ry];

            parentOf[ry] = rx;

            return true;
        }
    }

    long size(int x) {
        return sz[rootOf(x)];
    }
};

template<long MOD>
class Modulo {
private:

    long value;

    tuple<long, long> extendedEuclidean(long a, long b, long x = 1, long y = 0, long u = 0, long v = 1) const {
        if (b == 0) {
            return make_tuple(x, y);
        } else {
            long q = a / b;
            long r = a % b;
            x = x - (q * u);
            y = y - (q * v);
            return extendedEuclidean(b, r, u, v, x, y);
        }
    }

    long inverse() const {
        long x, y;
        tie(x, y) = extendedEuclidean(value, MOD);
        long gcd = value * x + MOD * y;
        assert(gcd == 1);
        return x % MOD;
    }

public:

    Modulo(long x) {
        if (x < 0) {
            x %= MOD;
            x += MOD;
        }

        value = x;
    }


    Modulo operator+(Modulo that) const { return Modulo((value + that.value) % MOD); }
    Modulo operator-(Modulo that) const { return Modulo((value - that.value + MOD) % MOD); }
    Modulo operator*(Modulo that) const {
        long a = value % MOD;
        long b = that.value % MOD;
        return Modulo((a * b) % MOD);
    }
    Modulo operator/(Modulo that) const { return Modulo(value) * Modulo(that.inverse()); }

    long get() {
        return value;
    }

};

const long MOD = 1000000007L;

using Mod1000000007 = Modulo<MOD>;

// 8進数から10進数
long base8_to_long(const vector<long>& v) {
    long ret = 0;
    for (long d/*igit*/ = 0; d < v.size(); ++d) {
        ret += v[d] * pow(8L, d);
    }
    return ret;
}

// 10進数から9進数
vector<long> long_to_base9(long n) {
    vector<long> v;
    while (n > 0) {
        int r = n % 9;
        v.push_back(r);
        n /= 9;
    }
    return v;
}

// 共線かどうかを判定する
// (b.y - a.y) / (b.x - a.x)
// (c.y - a.y) / (c.x - a.x)
bool colinear(Point& a, Point& b, Point& c) {
    auto [ax, ay] = a;
    auto [bx, by] = b;
    auto [cx, cy] = c;
    return (by - ay) * (cx - ax) == (bx - ax) * (cy - ay);
}

// Returns true if s is a palindrome, otherwise false.
bool palindrome(string s) {
    bool ok = true;
    rep(j, 0, s.size()/2) {
        if (s[j] != s[s.size()-1-j]) {
            ok = false;
            break;
        }
    }
    return ok;
}
