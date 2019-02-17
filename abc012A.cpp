#include <iostream>

using namespace std;

void swap(int &A, int &B) {
    int T = A;
    A = B;
    B = T;
}

int main() {
    int A, B;
    cin >> A >> B;

    swap(A, B);

    cout << A << " " << B << endl;

    return 0;
}
