#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, temp = 0, pos = -1, ele;
    printf("Enter size of array:\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements one by one:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Enter position of maximum of element to be searched:\n");
    scanf("%d",&pos);
    for (int i = 1; i <= 6; i++)
    {
        if (i == pos)
        {
            ele = arr[i+1];
            break;
        }
    }
    printf("%d position maximum element is %d", pos, ele);
    free(arr);
    return 0;
}