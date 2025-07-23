#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Total size for both stacks

typedef struct {
    int data[SIZE];
    int top1;
    int top2;
} DoubleStack;

// Initialize the double stack
void initDoubleStack(DoubleStack *ds) {
    ds->top1 = -1;
    ds->top2 = SIZE;
}

// Check if the double stack is full
int isFull(DoubleStack *ds) {
    return ds->top1 + 1 == ds->top2;
}

// Check if stack1 is empty
int isEmptyStack1(DoubleStack *ds) {
    return ds->top1 == -1;
}

// Check if stack2 is empty
int isEmptyStack2(DoubleStack *ds) {
    return ds->top2 == SIZE;
}

// Push element into Stack1
void pushStack1(DoubleStack *ds, int value) {
    if (isFull(ds)) {
        printf("Stack Overflow! Cannot push %d into Stack1\n", value);
        return;
    }
    ds->data[++ds->top1] = value;
    printf("%d pushed into Stack1\n", value);
}

// Push element into Stack2
void pushStack2(DoubleStack *ds, int value) {
    if (isFull(ds)) {
        printf("Stack Overflow! Cannot push %d into Stack2\n", value);
        return;
    }
    ds->data[--ds->top2] = value;
    printf("%d pushed into Stack2\n", value);
}

// Pop element from Stack1
int popStack1(DoubleStack *ds) {
    if (isEmptyStack1(ds)) {
        printf("Stack1 Underflow!\n");
        return -1;
    }
    return ds->data[ds->top1--];
}

// Pop element from Stack2
int popStack2(DoubleStack *ds) {
    if (isEmptyStack2(ds)) {
        printf("Stack2 Underflow!\n");
        return -1;
    }
    return ds->data[ds->top2++];
}

// Display both stacks
void display(DoubleStack *ds) {
    printf("Stack1 (Left to Right): ");
    for (int i = 0; i <= ds->top1; i++) {
        printf("%d ", ds->data[i]);
    }
    printf("\n");

    printf("Stack2 (Right to Left): ");
    for (int i = SIZE - 1; i >= ds->top2; i--) {
        printf("%d ", ds->data[i]);
    }
    printf("\n");
}

/* -------- Main Function -------- */
int main() {
    DoubleStack ds;
    initDoubleStack(&ds);

    pushStack1(&ds, 10);
    pushStack1(&ds, 20);
    pushStack1(&ds, 30);

    pushStack2(&ds, 100);
    pushStack2(&ds, 200);

    display(&ds);

    printf("%d popped from Stack1\n", popStack1(&ds));
    printf("%d popped from Stack2\n", popStack2(&ds));

    display(&ds);

    return 0;
}
