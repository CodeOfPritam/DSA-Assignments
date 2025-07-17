#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,i,j,k=0;
    printf("Enter size of first array:");
    scanf("%d",&n);
    printf("Enter size of second array:");
    scanf("%d",&m);

    int *a=(int *)malloc(n*sizeof(int));
    int *b=(int *)malloc(m*sizeof(int));
    int *c=(int *)malloc((m+n)*sizeof(int));

    printf("Enter %d elements in the first array in sorted manner:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    i=0;j=0;
    printf("Enter %d elements in the second array in sorted manner:\n",m);
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);

    i=0;j=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    while(i<n)
    {
        c[k++]=a[i++];
    }
    while(j<m)
    {
        c[k++]=b[j++];
    }
    printf("The merged array:\n");
    for(i=0;i<(m+n);i++)
    {
        printf("%d\t",c[i]);
    }
    printf("\n");
    free(a);free(b);free(c);
    return 0;
}