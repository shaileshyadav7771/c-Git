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

void SortedInsert(struct Node *P, int x)
{   // creating and Intializing a new Node
    struct Node *q,*t = NULL;
    // creating a Node
    t = (struct Node*)malloc(sizeof(struct Node));
    // Intializing value x
    t->data = x;
    t->next=NULL;

    //speacial case1:
    // we need to check if the first Node if NULL means no Node and
    //It should be point to the Node which we created.
    if(first == NULL)
        first = t;
    else
    {
        //iterating over link list to find out the Node
        while(P && P->data <x)
        {
            //move pointer
            q=P;
            P=q->next;
        }
        // means we found the place where we need to insert Node
        // special case 2:
        //Note: Need to verify the place were we stopped is the first Node id so then we need to insert Node before first(Left side)
        if(P == first)
        {   //temp node next'll point first node
            t->next=first;
            //move first pointer to new Node where t is pointing.
            first=t;
        }
        else
        {
            //Insert Node
            t->next=q->next;
            q->next=t;
        }
    }
}


int main()
{
    int A[]={10,20,30,40,50,60};
    create(A, 5);
    Display(first);
    printf("\n********************************\n");
    SortedInsert(first, 25);
    Display(first);
    return 0;
}
