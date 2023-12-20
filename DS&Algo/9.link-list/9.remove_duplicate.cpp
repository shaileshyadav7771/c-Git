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

void Remove_duplicate_node(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;   //in c free(q);
            q = p->next;
        }
    }
}

int main()
{
    int A[]={10,20,20,400,400,60};
    create(A, 6);
    Remove_duplicate_node(first);
    Display(first);
    return 0;
}
