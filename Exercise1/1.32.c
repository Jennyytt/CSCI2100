#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int res[n];
    for (int i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);
        int arr[size];
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[j]);
        }
        int n = arr[0];
        for (int j = 1; j < size; j++) {
            n ^= arr[j];  //^ = bitwise xor
        }
        res[i] = n;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}
