#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &rows, &cols);

    // Allocate single block
    int *arr = (int *)malloc(rows * cols * sizeof(int));

    // Input elements
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", (arr + i * cols + j));
        }
    }

    // Output elements
    printf("The 2D array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(arr + i * cols + j));
        }
        printf("\n");
    }
    int ele, row, col, f = 0;
    printf("Enter the element to be searched:\n");
    scanf("%d", &ele);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (ele == *(arr + i * cols + j))
            {
                row = i;
                col = j;
                f = 1;
                break;
            }
        }
    }
    if (f != 0)
    {
        printf("%d is found at %d th row and %d th column",ele,row,col);
    }
    else
    {
        printf("Element is not present in the 2D array");
    }
    // Free memory
    free(arr);

    return 0;
}
