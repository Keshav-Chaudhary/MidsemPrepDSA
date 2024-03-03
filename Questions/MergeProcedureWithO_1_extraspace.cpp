#include <iostream>
using namespace std;

int find_min_idx(int arr[], int start, int end) {
    int min = arr[start];
    int i, idx = start;
    for (i = start + 1; i <= end; i++) {
        if (arr[i] < min) {
            min = arr[i];
            idx = i;
        }
    }
    return idx;
}

void merge(int arr[], int start, int mid, int end) {
    int i;
    for (i = start; i < end; i++) {
        int idx = find_min_idx(arr, i, end);
        if (idx != i) {
            int t = arr[i];
            arr[i] = arr[idx];
            arr[idx] = t;
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    merge(arr, 0, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

