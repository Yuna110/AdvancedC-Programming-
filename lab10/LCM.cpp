#include <iostream>
using namespace std;

/* GCD function */
int gcd(int a, int b) {
    return (b == 0) ? abs(a) : gcd(b, a % b);
}

/* LCM of two numbers */
int lcm(int a, int b) {
    return abs(a / gcd(a, b) * b);
}

/* LCM of multiple numbers */
int lcmMultiple(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main() {
    int numbers[] = {4, 6, 8};   // Change numbers here
    int n = sizeof(numbers) / sizeof(numbers[0]);

    cout << "LCM is: " << lcmMultiple(numbers, n);

    return 0;
}