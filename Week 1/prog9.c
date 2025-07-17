#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, start, end;

    // Input size
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Dynamic allocation
    int *arr = (int *)malloc(n * sizeof(int));

    // Input elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input start and end positions (1-based)
    printf("Enter start and end positions to delete (1-based index):\n");
    scanf("%d %d", &start, &end);

    // Validate range
    if (start < 1 || end > n || start > end) {
        printf("Invalid range!\n");
        free(arr);
        return 1;
    }

    // Convert to 0-based
    start--;
    end--;

    // Calculate number of elements to remove
    int removeCount = end - start + 1;

    // Shift elements
    for (i = end + 1; i < n; i++) {
        arr[i - removeCount] = arr[i];
    }

    // Adjust size
    n -= removeCount;

    // Reallocate memory to new size
    arr = (int *)realloc(arr, n * sizeof(int));
    if (!arr && n > 0) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Output the updated array
    printf("Array after deletion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
