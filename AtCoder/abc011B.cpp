#include <iostream>

using namespace std;

int main() {
    string S;
    cin >> S;

    for (string::iterator it = S.begin(); it != S.end(); ++it) {
        if (it == S.begin()) {
            (*it) = toupper(*it);
        } else {
            (*it) = tolower(*it);
        }
    }

    cout << S << endl;

    return 0;
}
