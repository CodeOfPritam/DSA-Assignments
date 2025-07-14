#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the elements one by one:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int min=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
            min=arr[i];
    } 
    printf("Minimum element of the array is %d\n",min);
    return 0;
}