#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if (n == 0 || n == 1) {
        printf("%lld\n", n);
        return 0;
    }

    long long left = 1, right = n, ans = 0;

    // Binary search for the square root
    while (left <= right) {
        long long mid = left + (right - left) / 2;

        // If mid*mid matches n exactly
        if (mid * mid == n) {
            ans = mid;
            break;
        }

        // If mid*mid is less than n, search the right half
        if (mid * mid < n) {
            ans = mid; // Store potential answer
            left = mid + 1;
        } 
        // If mid*mid is greater, search the left half
        else {
            right = mid - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}