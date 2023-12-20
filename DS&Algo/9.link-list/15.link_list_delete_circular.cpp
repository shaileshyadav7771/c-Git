#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*Head;   //global ptr will use required place and even as parameter

//create a circular link list
void create(int A[], int n)
{
    int i;
    struct Node *t,*last;
    //create a first node and point HEAD to it
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    //above is single Node circular next is pointing on same Node

    //for remaining Node..
    last = Head;
    for(i=1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last=t;
    }
}

void Display(struct Node *head)
{//Note: we are not modifying anything so will use Head ptr directly otherwise we
// should create a temp variable and then make changes to it..
    do
    {
        cout << "Data: " << head->data << ", Address: " << head << ", Next Address: " << head->next << endl;
        head = head->next;
    } while (head != Head);   //Head is global variable
    printf("\n");
}

int Length(struct Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}

int Delete(struct Node *p, int index) //p head
{
    struct Node *q;
    int i,x;

    if (index < 0 || index >Length(Head))
    {
        return -1;
    }
    if (index == 1)
    {
        // need to delete first node and point last to new node and move head to new node..
        while(p->next != Head) p=p->next;
        x=Head->data;
        //aftercopying data we also need to make sure It's not the last
        //Node if last node then head and p both will be pointing on same node.
        if(Head==p)
        {
            free(Head);   //free in c
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        //if index is not 1 then process is same like linearlink list
        for(i=0; i<index-2; i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}


int main()
{
    int A[] = {7,8,9,10,11};
    create(A,5);  // circular link list creation
    Delete(Head,2);

    Display(Head);

    return 0;
}
