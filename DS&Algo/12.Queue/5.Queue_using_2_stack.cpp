#include <stdio.h>
#include <stdlib.h>

// Define the structure for the stack
struct Stack {
    int Size;
    int Top;
    int *S;
};

// Function to push an element onto the stack
void push(struct Stack *st, int x) {
    if (st->Top == st->Size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    st->Top++;
    st->S[st->Top] = x;
}

// Function to pop an element from the stack
int pop(struct Stack *st) {
    int x = -1;
    if (st->Top == -1) {
        printf("Stack Underflow\n");
    } else {
        x = st->S[st->Top];
        st->Top--;
    }
    return x;
}

// Function to check if the stack is empty
int isEmpty(struct Stack st) {
    return st.Top == -1 ? 1 : 0;
}

// Function to enqueue an element into the queue
void enqueue(struct Stack *S1, int x) {
    // Check if there's space available in S1
    if (S1->Top == S1->Size - 1) {
        printf("Queue is Full. Cannot enqueue.\n");
        return;
    }
    push(S1, x);
}

// Function to dequeue an element from the queue
int dequeue(struct Stack *S1, struct Stack *S2) {
    int x = -1;
    // Check if S2 is Empty
    if (isEmpty(*S2)) {
        // If S2 is Empty, transfer elements from S1 to S2
        if (isEmpty(*S1)) {
            printf("Queue is Empty.\n");
            return x;
        } else {
            while (!isEmpty(*S1)) {
                push(S2, pop(S1));
            }
        }
    }
    // Pop the element from S2
    return pop(S2);
}

int main() {
    struct Stack S1, S2;
    S1.Size = 5; // Size of the stacks
    S2.Size = 5;
    S1.Top = S2.Top = -1;
    S1.S = (int *)malloc(S1.Size * sizeof(int));
    S2.S = (int *)malloc(S2.Size * sizeof(int));

    enqueue(&S1, 10);
    enqueue(&S1, 20);
    enqueue(&S1, 30);
    enqueue(&S1, 40);
    enqueue(&S1, 50);

    printf("Dequeuing elements: ");
    printf("%d ", dequeue(&S1, &S2));
    printf("%d ", dequeue(&S1, &S2));
    printf("%d ", dequeue(&S1, &S2));
    printf("%d ", dequeue(&S1, &S2));
    printf("%d ", dequeue(&S1, &S2));
    printf("\n");

    return 0;
}
