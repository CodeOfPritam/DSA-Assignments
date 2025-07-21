#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size;
    printf("Enter the size of string: ");
    scanf("%d",&size);
    char word[size];
    printf("Enter the string: ");
    scanf("%s",&word);
    printf("The reversed string is: ");
    for(int i=size-1;i>=0;i--)
    {
        printf("%c",word[i]);
    }
    printf("\n");
    return 0;
}