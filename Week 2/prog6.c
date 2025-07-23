#include <stdio.h>
#include <stdlib.h>

/* -------- Stack ADT -------- */
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*) malloc(capacity * sizeof(int));
    return stack;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int value) {
    if (!isStackFull(stack)) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack Overflow!\n");
    }
}

int pop(Stack *stack) {
    if (!isStackEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return -1;  // Error value
}

int peek(Stack *stack) {
    if (!isStackEmpty(stack))
        return stack->data[stack->top];
    return -1;
}

void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

/* -------- Queue using 2 Stacks -------- */
typedef struct {
    Stack *s1;
    Stack *s2;
} Queue;

Queue* createQueue(int capacity) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->s1 = createStack(capacity);
    queue->s2 = createStack(capacity);
    return queue;
}

void enqueue(Queue *queue, int value) {
    push(queue->s1, value);
    printf("%d enqueued to queue\n", value);
}

int dequeue(Queue *queue) {
    if (isStackEmpty(queue->s1) && isStackEmpty(queue->s2)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    // If s2 is empty, move all elements from s1 to s2
    if (isStackEmpty(queue->s2)) {
        while (!isStackEmpty(queue->s1)) {
            push(queue->s2, pop(queue->s1));
        }
    }

    return pop(queue->s2);
}

void freeQueue(Queue *queue) {
    freeStack(queue->s1);
    freeStack(queue->s2);
    free(queue);
}

/* -------- Main Function -------- */
int main() {
    Queue *queue = createQueue(10);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    enqueue(queue, 40);
    printf("%d dequeued from queue\n", dequeue(queue));

    freeQueue(queue);
    return 0;
}
