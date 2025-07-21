#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

bool isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return true;
    else
        return false;
}

bool isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return true;
    else
        return false;
}

void Push(struct stack *ptr, int val) // Push Function
{
    if (isFull(ptr))
    {
        printf("Stack overflow!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int main()
{
    // struct stack s;
    // s.size=100;
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*sizeof(int));

    // struct stack *s;
    // s->size=100;
    // s->top=-1;
    // s->arr=(int *)malloc(s->size*sizeof(int));

    struct stack *sp= (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));


    printf("Stack has been created successfully!\n");

    Push(sp, 56);

    printf("Full after pushing : %d\n", isFull(sp));
    printf("Empty after popping : %d\n", isEmpty(sp));

    return 0;
}