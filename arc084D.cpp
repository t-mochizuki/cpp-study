#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

int solve(int K) {

    deque<pair<int, int> > dq;
    vector<bool> visited(K, false);

    dq.push_front(make_pair(1, 1));
    while (! dq.empty()) {
        pair<int, int> p = dq.front();
        dq.pop_front();

        int current = p.first, cnt = p.second;
        if (current == 0) return cnt;

        visited[current] = true;
        int next = (current + 1) % K;
        if (visited[next] == false) {
            dq.push_back(make_pair(next, cnt + 1));
        }

        next = (current * 10) % K;
        if (visited[next] == false) {
            dq.push_front(make_pair(next, cnt));
        }
    }

    return 0;
}

int main() {
    int K;
    scanf("%d", &K);

    int cnt = solve(K);
    printf("%d\n", cnt);

    return 0;
}
