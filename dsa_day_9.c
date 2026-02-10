#include <stdio.h>
#include <string.h>

int main() {
    // 1. Declare a character array large enough to hold the input
    char str[100005]; 

    // 2. Read the input string
    // We use %s because the problem guarantees no spaces
    if (scanf("%s", str) != 1) return 0;

    // 3. Setup the Two Pointers
    int start = 0;
    int end = strlen(str) - 1; // Point to the last character

    // 4. The Mirror Swap Loop
    while (start < end) {
        
        // Swap characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move pointers closer
        start++;
        end--;
    }

    // 5. Print the transformed mirror string
    printf("%s", str);

    return 0;
}