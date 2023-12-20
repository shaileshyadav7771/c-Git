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

int Delete(struct Node *P, int index)
{
    struct Node *q=NULL;
    int x =-1; // to store deleted variable

    // if index is out from range 1 to count using P passed ptr
    if (index < 1 || index > count(P))
    {
        return -1; // stating element is not deleted
    }

    // two cases inserting at first Node or at second Node
    // first case
    if (index == 1)
    {
        q = first;
        x = first->data;
        //change first pointer to point of second  node since 2nd node is first now
        first = first->next;
        free(q);
        return x; // return deleted value
    }
    else
    {
        //another index
        // we have already checked valid index case..
        for(int i=0; i<index-1; i++)
        {
            q=P;
            P=P->next;
        }
        // we have moved pointer where P is on current index Node and q on index-1
        // we'll remove current Node where P pointing so first let use P and link with q that is
        q -> next=P->next;
        x = P->data;
        free(P); // for c lang delete P in c++
        return x;
    }
}


int main()
{
    int A[]={10,20,30,40,50,60};
    create(A, 5);
    Display(first);
    printf("\n********************************\n");
    printf("Deleted element is : %d\n", Delete(first, 7));
    Display(first);
    return 0;
}
