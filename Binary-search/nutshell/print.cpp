#ifndef PRINT
#define PRINT 1

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace nutshell {

void print(vector<long> arr, int pos) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i == arr.size() - 1) {
            if (i == pos) {
                cout << "(" << arr[i] << ")" << endl;
            } else {
                cout << arr[i] << endl;
            }
        } else {
            if (i == pos) {
                cout << "(" << arr[i] << ")" << " ";
            } else {
                cout << arr[i] << " ";
            }
        }
    }
}

} // namespace nutshell

#endif // PRINT
