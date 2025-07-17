#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, newSize, i;

    // Step 1: Allocate initial array
    printf("Enter initial size of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 2: Input initial elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display current array
    printf("Current array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 3: Resize array
    printf("Enter new size of array: ");
    scanf("%d", &newSize);

    arr = (int *)realloc(arr, newSize * sizeof(int));

    // Step 4: If size increased, take extra inputs
    if (newSize > n) {
        printf("Enter %d new elements:\n", newSize - n);
        for (i = n; i < newSize; i++) {
            scanf("%d", &arr[i]);
        }
    }

    // Display resized array
    printf("Array after resizing:\n");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
