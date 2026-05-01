#include <stdio.h>

int isValid(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return 0;

        if (currentTime + boards[i] > maxTime) {
            painters++;
            currentTime = boards[i];
            if (painters > k) return 0;
        } else {
            currentTime += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > max) max = boards[i];
    }

    int left = max, right = sum, ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isValid(boards, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}