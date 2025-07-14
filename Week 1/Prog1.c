#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter %d elements int the array onr by one:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("Enter the element to be searched:\n");
    int ele,pos=-1;
    scanf("%d",&ele);
    for(int i=0;i<n;i++)
    {
        if(ele==arr[i])
        {
            pos=i;
            break;
        }
    }
    if(pos!=-1)
        printf("%d is found at index %d of the array\n",ele,pos);
    else
        printf("%d is not present in the array\n");
    free(arr);        
    return 0;
}