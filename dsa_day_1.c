#include <stdio.h>

int main() {
    
    int arr[1000]; 
    int n, pos, x, i;

   
    scanf("%d", &n);

   
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    scanf("%d", &pos);
    scanf("%d", &x);


    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    
    arr[pos - 1] = x;
     n++;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}