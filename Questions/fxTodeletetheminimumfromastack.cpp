#include <iostream>
#include <stack>

using namespace std;

// Function to delete the minimum element from a stack
int deleteMin(stack<int>& s) {
    // Base case: If the stack has only one element, remove and return it
    if (s.size() == 1) {
        int minVal = s.top();
        s.pop();
        return minVal;
    }
    
    // Recursive case: Pop the top element
    int topVal = s.top();
    s.pop();
    
    // Recur for the remaining stack
    int minVal = deleteMin(s);
    
    // If the popped element is the minimum, return the minimum found in the recursive call
    if (topVal == minVal) {
        return minVal;
    }
    // If the popped element is not the minimum, push it back and return the current minimum
    else {
        s.push(topVal);
        return minVal;
    }
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    s.push(5);

    cout << "Minimum value deleted: " << deleteMin(s) << endl;

    return 0;
}
