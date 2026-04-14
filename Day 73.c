#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    scanf("%s", s);

    int freq[256] = {0};

    // Count frequencies of all characters
    for (int i = 0; i < strlen(s); i++) {
        freq[(int)s[i]]++;
    }

    char result = '$';

    // Traverse string again to find the first char with frequency 1
    for (int i = 0; i < strlen(s); i++) {
        if (freq[(int)s[i]] == 1) {
            result = s[i];
            break;
        }
    }

    printf("%c\n", result);
    return 0;
}