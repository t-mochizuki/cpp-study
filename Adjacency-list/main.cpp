#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

typedef vector<vector<int> > Graph;

void solve() {
    int N, M; cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }

    for (int i = 0; i < N; ++i) {
        cout << i << ": ";
        for (vector<int>::iterator it = G[i].begin(); it != G[i].end(); ++it) {
            if (it == G[i].begin()) cout << *it;
            else cout << " " << *it;
        }
        cout << endl;
    }

    // for (vector<int> V : G) {
    //     for (int x : V) {
    //         cout << x << endl;
    //     }
    // }

    // for (Graph::iterator Vi = G.begin(); Vi != G.end(); ++Vi) {
    //     cout << Vi - G.begin() << ": ";
    //     for (vector<int>::iterator Vj = Vi->begin(); Vj != Vi->end(); ++Vj) {
    //         if (Vj == Vi->begin()) cout << *Vj;
    //         else cout << " " << *Vj;
    //     }
    //     cout << endl;
    // }
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
