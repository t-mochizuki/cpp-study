#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S;
    cin >> S;

    stack<char> st;
    REP(0, i, S.size()){
        st.push(S[i]);
    }

    stack<char> ts;
    int count = 0;
    REP(0, i, S.size()){
        char c = st.top(); st.pop();

        if (!ts.empty()) {
            char d = ts.top(); ts.pop();

            if (c != d) {
                count += 2;
            } else {
                ts.push(d); ts.push(c);
            }
        } else {
            ts.push(c);
        }
    }

    cout << count << endl;

    return 0;
}
