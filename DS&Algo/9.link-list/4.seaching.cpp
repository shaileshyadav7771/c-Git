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

struct Node * LinearSearch(struct Node *P, int key)
{
    while (P!=NULL)
    {
        if (key == P->data)
            return P;
        // if not matched then move P on the next Node..
        P=P->next;
    }
    // It's already checked all the elements so return NULL
    return NULL;
}

struct Node * RecursiveSearch(struct Node *P, int key)
{
    if (P==NULL)
        return NULL;
    if (key == P->data)
        return P;
    return RecursiveSearch(P->next, key);
}

struct Node * LinearSearch_move_to_head(struct Node *P, int key)
{
    struct Node *q;

    while (P != NULL)
    {
        if (key == P->data)
            {
                q->next = P->next;
                P->next = first;  // first we decalre global ptr
                first = P;
            }
        q = P;
        P = P->next;
    }
}

// Display function
void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50, 777, 70, 80, 90};
    create(A, 9);
    //since the fn is returning struct of Node ptr we need variable to hold that value
    // struct Node *temp = RecursiveSearch(first, 90);
    struct Node *temp = LinearSearch_move_to_head(first, 777);
    if (temp)
        printf("Key is Found : %d and next add : %d\n", temp->data, temp->next);
    else
        printf("Key is not Found\n");
    // for eg if we are searching 777 and if it's found then It'll become first element let us display link list.
    Display(first);
    return 0;
}
