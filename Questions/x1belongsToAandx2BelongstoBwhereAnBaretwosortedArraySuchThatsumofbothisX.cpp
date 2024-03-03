#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

pair<int, int> findPairWithSum(const vector<int>& arr1, const vector<int>& arr2, int target) {
    unordered_set<int> set;

    // Insert elements of arr1 into the set
    for (int num : arr1) {
        set.insert(num);
    }

    // Iterate through arr2 and check if there exists a corresponding element in the set
    for (int num : arr2) {
        int complement = target - num;
        if (set.find(complement) != set.end()) {
            return make_pair(complement, num);
        }
    }

    // If no pair is found, return an error pair
    return make_pair(-1, -1);
}

int main() {
    vector<int> A = {1, 3, 5, 7, 9};
    vector<int> B = {2, 4, 6, 8, 10};
    int target = 13;
    pair<int, int> result = findPairWithSum(A, B, target);
    if (result.first != -1 && result.second != -1) {
        cout << "Pair found: (" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "No pair found" << endl;
    }
    return 0;
}
