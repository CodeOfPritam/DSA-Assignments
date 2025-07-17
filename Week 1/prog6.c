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
    int min=*(arr+0*cols+0);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(*(arr+i*cols+j)<min)
            {
                min=*(arr+i*cols+j);
            }
        }
   }
    printf("Minimum element of the 2D array:%d\n",min);
    // Free memory
    free(arr);

    return 0;
}
