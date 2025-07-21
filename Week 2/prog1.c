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
        printf("Stack overflow! Cannot push into the stack.\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int Pop(struct stack *ptr) // Push Function
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow! Cannot pop from the stack.\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int Peek(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack underflow! No element is present in the stack.\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}
int Display(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        printf("The Stack is empty.\n");
    }
    else
    {
        for(int i=ptr->top;i>=0;i--)
        {
            printf("The value at index %d is %d\n",i,ptr->arr[ptr->top]);
        }
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

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    // printf("Stack has been created successfully!\n");

    // Push(sp,56);
    // Push(sp,56);
    // Push(sp,56);
    // Push(sp,70);
    // printf("Pushed %d into the stack\n",56);

    // printf("Popped %d from the stack\n",Pop(sp));

    // printf("Full after pushing : %d\n", isFull(sp));
    // printf("Empty after popping : %d\n", isEmpty(sp));

    // for(int j=0;j<sp->top+1;j++)
    // {
    //     printf("The value at position %d is %d\n",j,Peek(sp,j));
    // }

    int option, value;
    do
    {
        printf("*** Main Menu ***\n");
        printf("1. PUSH\n");
        printf("2. PULL\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("Enter your option:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the value to be pushed on stack:\n");
            scanf("%d", &value);
            Push(sp, value);
            break;
        case 2:
            value = Pop(sp);
            if (value != -1)
                printf("The value deleted from stack is %d\n", value);
            break;
        case 3:
            value = Peek(sp);
            if (value != -1)
                printf("The value stored at top of stack is %d\n", value);
            break;
        case 4:
            Display(sp);
            break;
        }
    }
    while (option<=4);
    printf("You have entered wrong choice!");
    return 0;
}