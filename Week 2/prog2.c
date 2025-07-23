#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r < q->f || q->f==-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full.\n");
        return;
    }
    if(q->f==-1 && q->r==-1)
    {
        q->f=0;
        q->r=0;
    }
    else
    {
        q->r++;
    }
    q->arr[q->r]=val;
}

int dequeue(struct queue *q)
{
    int a=-1;
    if (isEmpty(q))
    {
        printf("This queue is empty.\n");
    }
    else
    {
        a = q->arr[q->f];
        q->f++;
    }
    return a;
}

int peek(struct queue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("This queue is empty.\n");
    }
    else
    {
        a=q->arr[q->r];
    }
    return a;
}

void display(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("This queue is empty.\n");
    }
    else
    {
        for(int i=q->f;i<=q->r;i++)
        {
            printf("The value at index %d is %d\n",i,q->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    int option,val;
    do
    {
        printf("***Main Menu***\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Peek\n");
        printf("4. Display the queue\n");
        printf("Enter your option:\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the value to be inserted:\n");
                scanf("%d",&val);
                enqueue(q, val);
                break;
            case 2:
                printf("The element deleted is %d\n",dequeue(q));
                break;
            case 3:
                val=peek(q);
                if(val!=-1)
                printf("The value at front of the queue is %d\n",val);
                break;
            case 4:
                display(q);
                break;    

        }
    } while (option<=4);
    printf("You have entered wrong choice!");
    return 0;
}