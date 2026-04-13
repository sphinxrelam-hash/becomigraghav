#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    scanf("%s", s);

    int visited[256] = {0};
    char result = -1;

    // Traverse string left to right
    // The first character we see that has already been visited 
    // will naturally have the smallest second occurrence index.
    for (int i = 0; i < strlen(s); i++) {
        if (visited[(int)s[i]]) {
            result = s[i];
            break;
        }
        visited[(int)s[i]] = 1;
    }

    if (result != -1) {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}