#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

}*first=NULL;          

void create(int A[], int n)
{
    // we need to  iterarte over the array and create a Node from above values.
    int i;
    struct Node *temp, *last_node; // temp pointer don't disturb first and last_node'll help in determining last Node
    // link list is empty so create first new node and pointer first will point there
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];  // 10 assign to data and first is pointing to it.
    first->next=NULL; // fisrt Node so It is NULL
    // also last_node will point to the first Node..
    last_node = first;

    // Remaining Node we will create iterating over the array using for loop
    // will start from i=1 because i=0 first Node is already created..

    for(i=1; i<n; i++)
    {
        //each time need to create a new Node so will use same malloc fn
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data=A[i];  //20 ,30, 40...
        temp->next=NULL; //till now no next Node so pointing NULL.
        // let point the last_node to current Node
        last_node->next=temp;
        // last Node move on current node
        last_node=temp;
    }
}

// Display function
void Display(struct Node *p) // passed first pointer become p
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        //move p to next Node
        p=p->next;
    }
}


int main()
{
    int A[] = {10, 20, 30, 40, 50};
    //will create link list using above values
    create(A, 5);

    Display(first);
}
