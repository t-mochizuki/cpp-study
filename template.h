#include <stdio.h>
#include <iostream>
#include <cassert>
#include <cmath>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::terminate;
using std::vector;
using std::string;
using std::map;
using std::pair;
using std::make_pair;
using std::deque;
using std::queue;
using std::priority_queue;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;
using std::lower_bound;
using std::upper_bound;
using std::distance;
using std::to_string;
using std::greater;
using std::multiset;
using std::set;
using std::function;

// hint: 平方数 (四角数) とは、整数の自乗で表される非負整数のことである
// hint: 平方数Aと平方数Bの積は平方数Xになる

    // string t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                // printf("Case #%d: %s\n", x, t.c_str());
// #define M_PI 3.14159265358979323846 /* pi */
// #define M_PIl 3.141592653589793238462643383279502884L /* pi */

vector<pair<int, int>> ds = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

inline double deg2rad(double deg) { return M_PI * (deg / 180.0); }

long sigma(long n, long d) {
    return (n*(n+1)/2)*d;
}

class Point {
    double radian;
    double x, y;
public:
    double distance(const Point& o) const {
        return std::sqrt((x-o.x)*(x-o.x)+(y-o.y)*(y-o.y));
    }

    Point(long r, double deg) {
        radian = M_PI*(deg/180.0);
        y = r*std::cos(radian);
        x = r*std::sin(radian);
    }
};

class Rectangle {
public:

    int h = 0, w = 0;

    Rectangle() {}

    bool operator>(const Rectangle& other) const {
        return h > other.h;
    }
};

void output(int x, double ans) {
    printf("Case #%d: %.6f\n", x, ans);
}

void output(int x, int ans) {
    printf("Case #%d: %d\n", x, ans);
}

template<class K, class V>
istream& operator>>(istream& i, pair<K, V>& p) {
    i >> p.first >> p.second;
    return i;
}

template<class T>
istream& operator>>(istream& i, vector<T>& v) {
    rep(j, 0, v.size()) i >> v[j];
    return i;
}

template<class K, class T>
ostream& operator<<(ostream& o, pair<K, T>& p) {
    o << p.first;
    return o;
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
ostream& operator<<(ostream& o, set<T>& st) {
    bool first = true;
    for (auto x : st) {
        if (first) {
            o << x;
            first = false;
        } else o << " " << x;
    }
    return o;
}

template<class K, class T>
ostream& operator<<(ostream& o, map<K, T>& m) {
    bool first = true;
    for (const auto& [k, v] : m) {
        for (int i = 0; i < v; ++i) {
            if (first) {
                cout << k;
                first = false;
            } else {
                cout << " " << k;
            }
        }
    }
    return o;
}

template<class K, class T>
ostream& operator<<(ostream& o, map<K, T>& m) {
    for (const auto& [k, v] : m) {
        o << "{" << k << "," << v << "}";
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



const double EPSILON = 0.000000001;

template <class T>
using Point = pair<T, T>;

template <class T>
T dot(const Point<T>& a, const Point<T>& b) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    return x1*x2 + y1*y2;
}

Point<double> projection(const Point<long>& p, const Point<long>& q) {
    auto [x, y] = p;
    double ratio = 1.0 * dot(p, q) / dot(p, p);
    return Point<double>(ratio * x, ratio * y);
}

Point<double> rejection(const Point<long>& p, const Point<long>& q) {
    auto [px, py] = projection(p, q);
    auto [x, y] = q;
    return Point<double>(px-x, py-y);
}

// A length of between Point a and Point b.
double distance(const Point<long>& a, const Point<long>& b) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    return std::sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double distance(const vector<Point<long>>& v) {
    double val = 1e9;
    int n = v.size();
    rep(i, 0, n) {
        rep(j, i+1, n) {
            min(val, distance(v[i], v[j]));
        }
    }
    return val;
}

template <class T>
T cross(const Point<T>& a, const Point<T>& b) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    return x1*y2 - y1*x2;
}

double parallelogram(const Point<long>& a, const Point<long>& b) {
    return std::abs(cross(a, b));
}

int counterClockWise(const Point<long>& a, const Point<long>& b) {
    long z = cross(a, b);

    if (z > 0) {
        // cout << "COUNTER_CLOCKWISE" << endl;
        return 1;
    }

    if (z < 0) {
        // cout << "CLOCKWISE" << endl;
        return -1;
    }

    assert(z == 0);

    if (dot(a, b) < 0) {
        // cout << "ONLINE_BACK" << endl;
        return 2;
    } else if (dot(a, a) < dot(b, b)) {
        // cout << "ONLINE_FRONT" << endl;
        return -2;
    } else {
        // cout << "ON_SEGMENT" << endl;
        return 0;
    }
}

bool intersection(const Point<long>& a, const Point<long>& b, const Point<long>& c, const Point<long>& d) {
    auto [x0, y0] = a;
    auto [x1, y1] = b;
    auto [x2, y2] = c;
    auto [x3, y3] = d;

    Point<long> ab = Point<long>(x1-x0, y1-y0);
    Point<long> ac = Point<long>(x2-x0, y2-y0);
    Point<long> ad = Point<long>(x3-x0, y3-y0);

    if (counterClockWise(ab, ac) * counterClockWise(ab, ad) > 0) {
        return false;
    }

    Point<long> cd = Point<long>(x3-x2, y3-y2);
    Point<long> ca = Point<long>(x0-x2, y0-y2);
    Point<long> cb = Point<long>(x1-x2, y1-y2);

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
template<class T>
T gcd(T a, T b) {
  while (b > 0) {
    T r = a % b;
    a = b;
    b = r;
  }
  return a;
}

template<class T>
T gcd(const vector<T>& a) {
    long divisor = a[0];
    rep(i, 1, a.size()) {
        divisor = gcd(divisor, a[i]);
    }
    return divisor;
}



// least common multiple
// gcd(a, b) * lcm(a, b) == a * b
template<class T>
T lcm(T a, T b) {
    return a * (b / gcd(a, b));
}

template<class T>
T lcm(const vector<T>& a) {
    T multiple = a[0];
    rep(i, 1, a.size()) {
        multiple = lcm(multiple, a[i]);
    }
    return multiple;
}



long one = 1L;

template<class K, class T>
void counter(const vector<T>& a, map<K, T>& m) {
    rep(i, 0, a.size()) {
        if (m.count(a[i])) {
            m[a[i]] += one;
        } else {
            m[a[i]] = one;
        }
    }
}

template<class K, class T>
void counter(const T& x, map<K, T>& m) {
    if (m.count(x) == 0) {
        m[x] = one;
    } else {
        m[x] += one;
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
void factorization(T n, map<T, long>& m) {
    for (T i = 2; i * i <= n; ++i) {
        long tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        m[i] = tmp;
    }

    if (n != 1) m[n] = 1;
}

// 約数列挙
void divisor(long n, vector<long>& v) {
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

void divisor(long n, map<long, long>& m) {
    for (long i = 1; i * i <= n; ++i) {
        if (n % i != 0) {
            // 約数でない
            continue;
        }

        counter(i, m);

        long j = n/i;
        if (i != j) {
            // 商も約数である
            counter(j, m);
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

long base_to_long(long x, const long k) {
    vector<long> v;
    while (x > 0) {
        v.push_back(x % 10);
        x /= 10;
    }

    long ret = 0;
    for (long d/*igit*/ = 0; d < v.size(); ++d) {
        ret += v[d] * std::pow(k, d);
    }
    return ret;
}

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

// 10進数から2進数
vector<long> long_to_base2(long n) {
    vector<long> v;
    while (n > 0) {
        int r = n % 2;
        v.push_back(r);
        n /= 2;
    }
    return v;
}

int countZero(long i) {
    auto v = long_to_base2(i);

    int cnt = 0;

    rep(j, 0, v.size()) {
        if (v[j] == 0) {
            cnt++;
        } else {
            break;
        }
    }

    return cnt;
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

// An area of triangle is 1/2|ad-bc|.
// (0, 0), (a, b), (c, d)
using Point = pair<long, long>;

double triangle(const Point& a, const Point& b) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    return std::abs(x2*y1 - y2*x1) / 2.0;
}




bool validate(const string& s) {
    vector<bool> v;
    v.assign(26, false);
    char prev = '0';
    rep(i, 0, s.size()) {
        if (i == 0) {
            prev = s[i];
            v[s[i]-'A'] = true;
        } else {
            if (prev == s[i]) {
            } else {
                if (v[s[i]-'A']) {
                    return false;
                } else {
                    prev = s[i];
                    v[s[i]-'A'] = true;
                }
            }
        }
    }
    return true;
}

char last(const string& s) {
    return s[s.size()-1];
}

char head(const string& s) {
    return s[0];
}

bool primary(long n) {
    bool p = true;
    for (long i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            p = false;
            break;
        }
    }
    return p;
}

class Circle {
private:

public:

    Point<long> p;

    long r;

    Circle() {
        auto& [x, y] = p;
        cin >> x >> y >> r;
    }

    long distance(const Point<long>& q) {
        auto& [x, y] = p;
        auto& [qx, qy] = q;
        return (x-qx)*(x-qx)+(y-qy)*(y-qy);
    }

    int category(Circle& c) {
        assert(r>=c.r);
        long dd = distance(c.p);
        long ll = (r+c.r)*(r+c.r);
        if (dd > ll) return 5;
        else if (dd == ll) return 4;
        else {
            assert(dd < ll);

            long rr = (r-c.r)*(r-c.r);
            if (dd < rr) return 1;
            if (dd == rr) return 2;

            return 3;
        }
    }
};

using Graph = vector<vector<int>>;

class BreadthFirstSearch {
private:

    vector<bool> seen;

public:

    BreadthFirstSearch(int n) {
        seen.assign(n, false);
    }

    void search(Graph &g, int s) {
        queue<int> que;

        seen[s] = true;
        que.push(s);

        while (!que.empty()) {
            int u = que.front(); que.pop();
            for (auto v : g[u]) {
                if (seen[v]) continue;

                seen[v] = true;

                que.push(v);
            }
        }
    }

    bool isConnected() {
        for (auto b : seen) {
            if (not b) return false;
        }
        return true;
    }
};

class BreadthFirstSearch {
private:

    vector<int> seen;

public:

    BreadthFirstSearch(int n) {
        seen.assign(n, -1);
    }

    void search(Graph &g, int s) {
        queue<int> que;

        seen[s] = 0;
        que.push(s);

        while (!que.empty()) {
            int u = que.front(); que.pop();
            for (auto v : g[u]) {
                if (seen[v] != -1) continue;

                seen[v] = seen[u]+1;

                que.push(v);
            }
        }
    }

    bool isConnected() {
        for (auto b : seen) {
            if (b == -1) return false;
        }
        return true;
    }

    void print() {
        rep(j, 0, seen.size()) {
            cout << seen[j] << endl;
        }
    }
};

class BreadthFirstSearch {
private:

public:

    BreadthFirstSearch(int n) {
        seen.assign(n, -1);
    }

    vector<int> seen;

    bool isBipartited = true;

    void search(Graph &g, int s) {
        queue<int> que;

        seen[s] = 0;
        que.push(s);

        while (!que.empty()) {
            int u = que.front(); que.pop();
            for (auto v : g[u]) {
                if (seen[v] != -1) {
                    if (seen[v] == seen[u]) {
                        isBipartited = false;
                    }
                    continue;
                }

                seen[v] = seen[u] == 0 ? 1 : 0;

                que.push(v);
            }
        }
    }

    bool isConnected() {
        for (auto b : seen) {
            if (b == -1) return false;
        }
        return true;
    }

    void print() {
        rep(j, 0, seen.size()) {
            cout << seen[j] << endl;
        }
    }
};

using Grid = vector<string>;

int pair2index(int y, int x, int r, int c) {
    assert(y <= r);
    assert(x <= c);
    return x+c*y;
}

void grid2graph(const Grid& grid, Graph& g, int r, int c) {
    rep(j, 0, r) rep(i, 0, c) {
        if (i+1 < c and grid[j][i] == '.' and grid[j][i+1] == '.') {
            g[pair2index(j, i, r, c)].push_back(pair2index(j, i+1, r, c));
            g[pair2index(j, i+1, r, c)].push_back(pair2index(j, i, r, c));
        }
        if (j+1 < r and grid[j][i] == '.' and grid[j+1][i] == '.') {
            g[pair2index(j, i, r, c)].push_back(pair2index(j+1, i, r, c));
            g[pair2index(j+1, i, r, c)].push_back(pair2index(j, i, r, c));
        }
    }
}

long digitSum(long k) {
    long x = 0L;
    while (k > 0L) {
        x += k % 10L;
        k /= 10L;
    }
    return x;
}

int fib(int n, vector<int>& v, int mod) {
    if (v[n] != 0) return v[n];

    if (n == 1) {
        v[n] = 1;
    } else if (n == 2) {
        v[n] = 1;
    } else {
        assert(n >= 3);
        v[n] = fib(n-1, v, mod) + fib(n-2, v, mod);
    }

    v[n] %= mod;

    return v[n];
}

template<class T>
T power(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * power(base, exponent - 1);
    } else {
        T tmp = power(base, exponent / 2);
        return tmp * tmp;
    }
}

long power(long base, long exponent, long mod) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * (power(base, exponent - 1, mod) % mod);
    } else {
        long tmp = power(base, exponent / 2, mod) % mod;
        return (tmp * tmp) % mod;
    }
}

void pascal(int n, vector<long>& a) {
    if (n == 0) return ;

    cout << a << endl;

    vector<long> b;
    rep(i, 0, a.size()) {
        if (i == 0) {
            b.push_back(a[i]);
        } else {
            b.push_back(a[i-1]+a[i]);
        }
    }
    b.push_back(a.back());

    pascal(n-1, b);
}

long zero = 0L;

template<class T>
T pascal(T i, T j, vector<vector<long>>& v) {
    if (i < 0 or j < 0) return zero;

    if (v[i][j] != 0) return v[i][j];

    T a = pascal(i-1, j-1, v);
    T b = pascal(i-1, j, v);
    v[i][j] = a + b;

    return v[i][j];
};

long pascal(long i, long j, long mod, vector<vector<long>>& v) {
    if (v[i][j] != 0) return v[i][j];

    if (j == 0) {
        v[i][j] = 1;
    } else if (j == i) {
        v[i][j] = 1;
    } else {
        v[i][j] = pascal(i-1, j-1, mod, v) + pascal(i-1, j, mod, v);
    }

    v[i][j] %= mod;

    return v[i][j];
};

int pascal(int n, int r) {
    mint ret = 1;
    for (int i = n; i >= (n-r+1); --i) {
        ret *= i;
    }
    for (int i = 1; i <= r; ++i) {
        ret /= i;
    }
    return ret.val();
};

pair<int, int> knight(int a, int b) {
    // printf("a=%d b=%d\n", a, b);
    if (a == b*2) {
        return {0, b};
    } else if (b == a*2) {
        return {a, 0};
    } else if (a != 0 and b != 0 and a / 3 != 0 and b / 3 != 0) {
        a -= 3;
        b -= 3;
        auto [x, y] = knight(a, b);
        if (x == -1 and y == -1) {
            return {-1, -1};
        }
        return {1+x, 1+y};
    } else {
        return {-1, -1};
    }
}

// rock-paper-scissors
class Player {
public:

    int num = 0;
    int id = 0;
    string a;

    Player(int id, string a): id(id), a(a) {
    }

    void playAgainst(Player& you, int j) {
        if (a[j] == 'P' and you.a[j] == 'G') {
            num++;
            return ;
        }
        if (a[j] == 'G' and you.a[j] == 'C') {
            num++;
            return ;
        }
        if (a[j] == 'C' and you.a[j] == 'P') {
            num++;
            return ;
        }

        // draw
        if (a[j] == you.a[j]) {
            return ;
        }

        you.num++;
        return ;
    }


    bool operator>(const Player& other) const {
        if (num == other.num) {
            return id < other.id;
        }
        return num > other.num;
    }
};

ostream& operator<<(ostream& o, Player& v) { o << v.id; return o; }

struct Item {
    int w, v;
};

// 0-1 knapsack problem
class Knapsack {

    int n, w;
    vector<Item> items;
    vector<vector<int>> dp;

public:

    Knapsack(int n, int w): n(n), w(w) {
        items.resize(n);
        rep(i, 0, n) cin >> items[i].w >> items[i].v;

        dp.assign(n+1, vector<int>(w+1, -1));
        rep(j, 0, w+1) dp[n][j] = 0;
    }

    // O(2**n)
    int rec(int i, int j) {
        int res = 0;
        if (i == n) {
            res = 0;
        } else if (j < items[i].w) {
            res = rec(i+1, j);
        } else {
            res = std::max(rec(i+1, j), rec(i+1, j-items[i].w) + items[i].v);
        }
        return res;
    }

    // O(nw)
    void solve() {
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j <= w; ++j) {
                if (j < items[i].w) {
                    dp[i][j] = dp[i+1][j];
                } else {
                    dp[i][j] = std::max(dp[i+1][j], dp[i+1][j-items[i].w] + items[i].v);
                }
            }
        }
    }

    int val() {
        return dp[0][w];
    }
};

class Contest {

    int n, w = 0;
    vector<int> p;
    vector<vector<int>> dp;

public:

    Contest(int n): n(n) {
        p.resize(n);
        cin >> p;

        for (auto x : p) {
            w += x;
        }

        dp.assign(n+1, vector<int>(w+1, 0));
        dp[0][0] = 1;
    }

    // O(nw)
    void solve() {
        rep(i, 0, n) {
            rep(j, 0, w) {
                max(dp[i+1][j], dp[i][j]);
                max(dp[i+1][j+p[i]], dp[i][j]);
            }
        }
    }

    int val() {
        int res = 0;
        rep(j, 0, w+1) {
            if (dp[n][j] != 0) res++;
        }
        return res;
    }
};

class LongestCommonSubsequence {
private:

    string s, t;
    vector<vector<int>> dp;

public:

    LongestCommonSubsequence() {
        cin >> s >> t;
        dp.assign(s.size()+1, vector<int>(t.size()+1, 0));
    }

    void solve() {
        rep(i, 0, s.size()) {
            rep(j, 0, t.size()) {
                if (s[i] == t[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
    }
};

// O(|a|*log(|a|))
template<class T>
size_t longest_increasing_subsequence(const vector<T> &a, bool strict) {
  vector<T> v;
  for(auto &x : a) {
    auto it = v.begin();
    if(strict) it = lower_bound(v.begin(), v.end(), x);
    else it = upper_bound(v.begin(), v.end(), x);
    if(v.end() == it) v.emplace_back(x);
    else *it = x;
  }
  return v.size();
}

using Item = pair<int, int>;

// knapsack problem
class Knapsack {

    int n, W;
    vector<Item> items;
    vector<vector<int>> dp;

public:

    Knapsack(int n, int W): n(n), W(W) {
        items.resize(n);
        cin >> items;
        dp.assign(n+1, vector<int>(W+1, 0));
    }

    void naive() {
        rep(i, 0, n) {
            auto [v, w] = items[i];
            rep(j, 0, W+1) {
                for (int k = 0; k*w <= j; ++k) {
                    dp[i+1][j] = std::max(dp[i+1][j], dp[i][j-k*w] + k*v);
                }
            }
        }
    }

    void solve() {
        rep(i, 0, n) {
            auto [v, w] = items[i];
            rep(j, 0, W+1) {
                if (j-w >= 0) {
                    dp[i+1][j] = std::max(dp[i][j], dp[i+1][j-w] + v);
                } else {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
    }

    int val() {
        return dp[n][W];
    }
};

bool is_ascending_order(const vector<int>& a) {
    rep(i, 0, a.size()) {
        if (i == 0) continue;
        else {
            if (a[i-1] > a[i]) {
                return false;
            }
        }
    }
    return true;
}

template<class T> void cumulative_sum(const vector<T>& v, vector<T>& c) {
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0) c.push_back(v[i]);
        else c.push_back(v[i]+c[i-1]);
    }
}

// 数列vにv[i]以下の要素が何個あるか
template<class T> void counter(const vector<T>& v, vector<T>& c) {
    assert(c.size() == 2*100000+1);

    for (int i = 0; i < v.size(); ++i) {
        c[v[i]]++;
    }

    for (int i = 0; i < c.size(); ++i) {
        if (i == 0) c[i] = c[i];
        else c[i] += c[i-1];
    }
}
