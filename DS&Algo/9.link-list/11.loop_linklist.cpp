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

int isLoop(struct Node *first)
{
    struct Node * p, *q;
    p=q=first;
    do
    {
        p = p->next;
        q = q->next;
        //2nd step is condition and need to move if not NULL
        q = q != NULL ? q->next : NULL; // OR q = q?q->next:q;
    }while (p && q && p != q);

    if(p = q)           // means loop
        return 1;
    else
        return 0; // linear case
}

int main()
{
    int A[]={10,20,30,40,50,60};
    create(A, 6);
    // we need to form loop above A is linear so we'll take two pointer.
    struct Node *t1,*t2;
    //will make t1 point on Node 30
    t1=first->next->next;
    //same way let us make t2 point on last Node 60
    t2=first->next->next->next->next->next;
    //loop
    t2->next = t1;

    printf("%d\n", isLoop(first));
    return 0;
}
