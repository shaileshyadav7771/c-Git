#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    //remaining Node
    for(i=1; i<n; i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next=NULL;
        last->next = t;
        last=t;
    }
}

void Display(struct Node *P)
{
    while(P != NULL)
        {
            printf("%d ", P->data);
            P=P->next;
        }
}

int count(struct Node *first_node)
{
    int l=0;
    while (first_node)
    {
        l++;
        first_node = first_node->next;
    }
    printf("Total Node: %d\n", l);
    return l;
}

int is_Sorted(struct Node *P)
{
    int x = -65536;

    while(P != NULL)
    {
        if(P->data < x)
            return 0;
        x = P->data;
        P = P->next;
    }
    return 1;
}

int main()
{
    int A[]={10,20,30,400,50,60};
    create(A, 5);
    if (is_Sorted(first))
    {
        printf("Sorted\n");
    }
    else
    {
        printf("Not Sorted\n");
    }
    Display(first);
    return 0;
}
