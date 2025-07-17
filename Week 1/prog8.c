#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m, n, i, j, k = 0;
    printf("Enter size of first array: ");
    scanf("%d", &n);
    printf("Enter size of second array: ");
    scanf("%d", &m);

    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(m * sizeof(int));
    int *c = (int *)malloc((m + n) * sizeof(int));

    printf("Enter %d elements in the first array (unsorted allowed):\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter %d elements in the second array (unsorted allowed):\n", m);
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);

    /* Copy both arrays into c */
    for (i = 0; i < n; i++)
        c[k++] = a[i];
    for (i = 0; i < m; i++)
        c[k++] = b[i];

    /* Sort merged array using Bubble Sort */
    for (i = 0; i < m + n - 1; i++) {
        for (j = 0; j < m + n - i - 1; j++) {
            if (c[j] > c[j + 1]) {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }

    printf("The merged (sorted) array:\n");
    for (i = 0; i < (m + n); i++)
        printf("%d\t", c[i]);
    printf("\n");

    free(a);
    free(b);
    free(c);
    return 0;
}
