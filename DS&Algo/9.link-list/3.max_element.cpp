#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Max(struct Node *P)
{
    int max = 0;
    while(P)
    {
        if (P -> data > max)
            max = P -> data;
        P= P->next;
    }
    return max;
}

int RecursiveMax(struct Node *P)
{
    int x=0;
    if(P==NULL)
        return 0;
    x = RecursiveMax(P->next);
    if (x > P->data)
        return x;
    else return P->data;
}


int main()
{
    int A[] = {10, 20, 30, 40, 50, 777, 70, 80, 90};
    create(A, 9);
    printf("Max number is: %d\n",Max(first));
    printf("Max number is: %d\n",RecursiveMax(first));

    return 0;
}
