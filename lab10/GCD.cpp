#include <iostream>
using namespace std;

// Function to find GCD of two numbers
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Function to find GCD of an array
int gcdMultiple(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }
    return result;
}

int main() {
    int numbers[] = {24, 36, 60, 48};   // Change numbers here
    int n = sizeof(numbers) / sizeof(numbers[0]);

    cout << "GCD is: " << gcdMultiple(numbers, n);

    return 0;
}