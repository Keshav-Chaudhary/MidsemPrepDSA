#include <iostream>
#include <vector>

using namespace std;

void printCombinationsUtil(const vector<int>& arr, int n, int r, int index, vector<int>& combination) {
    // If we have selected r elements, print the combination
    if (combination.size() == r) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // If we have reached the end of the array, return
    if (index == n)
        return;

    // Include the current element and recur for remaining elements
    combination.push_back(arr[index]);
    printCombinationsUtil(arr, n, r, index + 1, combination);

    // Exclude the current element and recur for remaining elements
    combination.pop_back();
    printCombinationsUtil(arr, n, r, index + 1, combination);
}

void printCombinations(const vector<int>& arr, int n, int r) {
    vector<int> combination;
    printCombinationsUtil(arr, n, r, 0, combination);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    int r =2 ; // Change r to the desired combination size
    cout << "Combinations of size " << r << " are:\n";
    printCombinations(arr, n, r);
    return 0;
}
