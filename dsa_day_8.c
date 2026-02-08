#include <stdio.h>

// Recursive function to calculate a^b
long long power(int base, int exp) {
    // Base Case: Anything to the power of 0 is 1
    if (exp == 0) {
        return 1;
    }
    
    // Recursive Step: base * base^(exp-1)
    return base * power(base, exp - 1);
}

int main() {
    int a, b;
    
    // Read input
    if (scanf("%d %d", &a, &b) != 2) return 0;

    // Calculate and print result
    // We use long long to prevent overflow for large results
    printf("%lld", power(a, b));

    return 0;
}