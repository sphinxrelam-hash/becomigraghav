#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    double timeToTarget;
};

// Sort cars by position descending (closest to target first)
int compare(const void *a, const void *b) {
    return ((struct Car *)b)->position - ((struct Car *)a)->position;
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    struct Car cars[n];
    int pos, speed;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos, &speed);
        cars[i].position = pos;
        cars[i].timeToTarget = (double)(target - pos) / speed;
    }

    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double maxTimeSeen = 0;

    // Traverse starting from cars closest to the target
    for (int i = 0; i < n; i++) {
        // If a car takes longer than the fleet ahead, it forms a new fleet
        if (cars[i].timeToTarget > maxTimeSeen) {
            maxTimeSeen = cars[i].timeToTarget;
            fleets++;
        }
    }

    printf("%d\n", fleets);
    return 0;
}