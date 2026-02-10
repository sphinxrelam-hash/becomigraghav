#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    
    // 1. Read the input string
    if (scanf("%s", str) != 1) return 0;

    // 2. Initialize Two Pointers
    int start = 0;
    int end = strlen(str) - 1;
    
    // Assume it is a palindrome until proven otherwise
    int isPalindrome = 1; 

    // 3. Loop until pointers meet
    while (start < end) {
        
        // If mismatch found, it's not a palindrome
        if (str[start] != str[end]) {
            isPalindrome = 0; // False
            break;            // Stop checking
        }
        
        // Move pointers inward
        start++;
        end--;
    }

    // 4. Print the result
    if (isPalindrome) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}