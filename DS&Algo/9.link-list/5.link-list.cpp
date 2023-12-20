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

void Insert(struct Node *first_ptr, int index, int value)
{
    struct Node *t;
    int i;
    printf("index is : %d\n", index);
    if(index < 0 || index > count(first_ptr))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=value;

    if (index == 0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        struct Node *P = first;
        for(i=0; i<index-1; i++)
            P=P->next;
        //we have bring P to N-1 node
        t->next = P->next;
        // and the Node where currently P is ther will point to temp/new Node
        P ->next =t;
    }
}


int main()
{
    int A[]={10,20,30,40,50,60};
    create(A,6);
    Insert(first,0,77);
    Insert(first,1,70);
    Insert(first,2,100);

    Display(first);
    return 0;
}

// O/P:
// index is : 0
// Total Node: 6
// index is : 1
// Total Node: 7
// index is : 2
// Total Node: 8
// 77 70 100 10 20 30 40 50 60
// Press any key to continue . . .