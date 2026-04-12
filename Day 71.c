#include <stdio.h>
#include <string.h>

int main() {
    int m, q;
    // Read table size and number of operations
    scanf("%d %d", &m, &q);

    int hashTable[m];
    // Initialize hash table with -1 (empty)
    for (int i = 0; i < m; i++) hashTable[i] = -1;

    for (int k = 0; k < q; k++) {
        char op[10];
        int val;
        scanf("%s %d", op, &val);

        if (strcmp(op, "INSERT") == 0) {
            // Quadratic probing for insertion
            for (int i = 0; i < m; i++) {
                int idx = (val % m + i * i) % m;
                if (hashTable[idx] == -1) {
                    hashTable[idx] = val;
                    break;
                }
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;
            // Quadratic probing for searching
            for (int i = 0; i < m; i++) {
                int idx = (val % m + i * i) % m;
                if (hashTable[idx] == val) {
                    found = 1;
                    break;
                }
                if (hashTable[idx] == -1) break; // Stop if empty slot found
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    return 0;
}