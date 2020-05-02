#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

struct Intersection {
    int x, y;
};

int main() {
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int X, Y; cin >> X >> Y;
        string M; cin >> M;

        vector<Intersection> v;
        v.push_back((Intersection){X, Y});
        for (int i = 0; i < M.size(); ++i) {
            if (M[i] == 'N') {
                Y++;
            } else if (M[i] == 'S') {
                Y--;
            } else if (M[i] == 'E') {
                X++;
            } else if (M[i] == 'W') {
                X--;
            }
            v.push_back((Intersection){X, Y});
        }

        Intersection me = (Intersection){0, 0};
        vector<Intersection> w;
        w.push_back(me);
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].x != me.x) {
                me.x += (v[i].x - me.x) > 0 ? 1 : -1;
            } else if (v[i].y != me.y) {
                me.y += (v[i].y - me.y) > 0 ? 1 : -1;
            } else {
            }
            w.push_back(me);
        }

        int ans = 1005;
        for (int j = 0; j < w.size(); ++j) {
            for (int i = j; i < v.size(); ++i) {
                if (w[j].x == v[i].x && w[j].y == v[i].y) {
                    ans = min(ans, i);
                    break;
                }
            }
        }

        if (ans == 1005) {
            printf("Case #%d: IMPOSSIBLE\n", x);
        } else {
            printf("Case #%d: %d\n", x, ans);
        }
    }
    return 0;
}
