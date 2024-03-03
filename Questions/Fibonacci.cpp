#include <iostream>

using namespace std;

// Iterative approach
int fibonacci_iterative(int n) {
    int a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Recursive approach
int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n = 10; // Change the value of n to get different Fibonacci numbers
    cout << "Fibonacci number at position " << n << " (iterative): " << fibonacci_iterative(n) << endl;
    cout << "Fibonacci number at position " << n << " (recursive): " << fibonacci_recursive(n) << endl;
    return 0;
}
