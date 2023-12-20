#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create_first_link_list(int A[], int n)
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

void create_second_link_list(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

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

// void concat(struct Node *first, struct Node *second)
// {
//     third = first;
//     while(first->next !=NULL)
//         {
//             first=first->next;
//         }
//     first->next=second;
// }

void Merge(struct Node *first1, struct Node *second2)
{
    // we need last pointer for merging..(
        // last ptr used in creation of first & second link list is local to scope of function
    // so not a global pointer)
    struct Node *last;
    //third pointer we will check which Node first value less It'll point on it.
    if(first1->data < second2->data)
    {
        third = last = first1;
        first1=first1->next;
        third->next=NULL;
    }
    else
    {
        third = last = second2;
        second2=second2->next;
        third->next=NULL;
    }

    while(first1 && second2)
    {
        if(first1->data < second2->data)
        {
            last->next = first1;
            last=first1;
            first1=first1->next;
            last->next=NULL;
        }
        else
        {
            last->next = second2;
            last=second2;
            second2=second2->next;
            last->next=NULL;
        }
    }
    // if first is not end means not NULL then let last pointer point to remaining elements of first
    if (first1) last->next=first1;
    //same way
    if (second2) last->next=second2;
}


int main()
{
    int A[]={10,20,22,277,500,600};
    create_first_link_list(A, 6);

    int B[]={11,40,70,200,700,6000};
    create_second_link_list(B, 6);

    printf("First linked list is: \n");
    Display(first);
    printf("\n\n");

    printf("second linked list is: \n");
    Display(second);
    printf("\n\n");

    // concat(first, second);
    // printf("Concatination Result check: \n");
    // Display(third);
    // printf("\n\n");

    Merge(first, second);
    printf("Concatination Result after Merge: \n");
    Display(third);


    return 0;
}
