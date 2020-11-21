#ifndef BINARY_SEARCH
#define BINARY_SEARCH 1

#include <vector>

using std::vector;

namespace nutshell {

const int KEY_NOT_FOUND = -1;

int binary_search(vector<long> arr, int value, int left, int right) {
    if (right < left) {
        return KEY_NOT_FOUND;
    } else {
        int pivot = left + (right - left) / 2;
        if (value < arr[pivot]) {
            return binary_search(arr, value, left, pivot - 1);
        } else if (arr[pivot] < value) {
            return binary_search(arr, value, pivot + 1, right);
        } else {
            return pivot;
        }
    }
}

int binary_search_alternative(vector<long> arr, int value, int left, int right) {
    if (right == left) {
        if (arr[right] == value) {
            return right;
        } else {
            return KEY_NOT_FOUND;
        }
    } else {
        // the ceiling of (L + R) / 2
        int pivot = left + (right - left + 1) / 2;
        if (value < arr[pivot]) {
            return binary_search_alternative(arr, value, left, pivot - 1);
        } else {
            return binary_search_alternative(arr, value, pivot, right);
        }
    }
}

} // namespace nutshell

#endif // BINARY_SEARCH
