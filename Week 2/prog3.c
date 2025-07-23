#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------- Stack ADT -------- */
typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

// Create a stack
Stack* createStack(int capacity) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*) malloc(capacity * sizeof(char));
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, char c) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = c;
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

/* -------- Reverse Function -------- */
void reverseString(char *str) {
    int length = strlen(str);
    Stack *stack = createStack(length);

    // Push all characters onto stack
    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }

    // Pop all characters to reverse
    for (int i = 0; i < length; i++) {
        str[i] = pop(stack);
    }

    freeStack(stack);
}

/* -------- Main -------- */
int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
