#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/* ---------------- Stack ADT ---------------- */
typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*) malloc(capacity * sizeof(char));
    return stack;
}

bool isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isStackFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, char c) {
    if (!isStackFull(stack)) {
        stack->data[++stack->top] = c;
    }
}

char pop(Stack *stack) {
    if (!isStackEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

/* ---------------- Queue ADT ---------------- */
typedef struct {
    char *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->data = (char*) malloc(capacity * sizeof(char));
    return queue;
}

bool isQueueEmpty(Queue *queue) {
    return queue->size == 0;
}

bool isQueueFull(Queue *queue) {
    return queue->size == queue->capacity;
}

void enqueue(Queue *queue, char c) {
    if (!isQueueFull(queue)) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->data[queue->rear] = c;
        queue->size++;
    }
}

char dequeue(Queue *queue) {
    if (!isQueueEmpty(queue)) {
        char c = queue->data[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        return c;
    }
    return '\0';
}

void freeQueue(Queue *queue) {
    free(queue->data);
    free(queue);
}

/* ---------------- Palindrome Check ---------------- */
bool is_palindrome(char *text) {
    int length = strlen(text);
    Stack *stack = createStack(length);
    Queue *queue = createQueue(length);

    // Filter text: keep only letters, convert to lowercase
    for (int i = 0; i < length; i++) {
        if (isalpha((unsigned char)text[i])) {
            char c = tolower((unsigned char)text[i]);
            push(stack, c);
            enqueue(queue, c);
        }
    }

    // Compare stack (reverse order) and queue (forward order)
    while (!isStackEmpty(stack) && !isQueueEmpty(queue)) {
        if (pop(stack) != dequeue(queue)) {
            freeStack(stack);
            freeQueue(queue);
            return false;
        }
    }

    freeStack(stack);
    freeQueue(queue);
    return true;
}

/* ---------------- Main with Tests ---------------- */
int main() {
    char *tests[] = {
        "", "a", "aa", "aba", "abba",
        "Taco cat",
        "Madam, I'm Adam",
        "A man, a plan, a canal: Panama",
        "Doc, note: I dissent. A fast never prevents a fatness. I diet on cod.",
        "Not a palindrome"
    };
    
    int n = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < n; i++) {
        printf("\"%s\" -> %s\n", tests[i], is_palindrome(tests[i]) ? "Palindrome" : "Not Palindrome");
    }

    return 0;
}
