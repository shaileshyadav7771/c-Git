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

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;  //temp ptr
    int i;

    //validate the index value
    if(index < 0 || index >= Length(p))
    {
        //don't insert anything just return
        return;
    }

    if(index == 0)
    {
        //means store value vbefore head Node.
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        // since we are inserting before head let us check if head is NULL if so then we are creating
        // first node and head next should point on itself.
        if(Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            //means some node is already there we need to move till last Node
            while(p->next!=Head)
            {
                p=p->next;
            }
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    //index is not == 0
    else
    {
        for(i=0; i<index-1; i++)
        {
            p = p->next;
        }
        //create a new Node and data
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        //Modify the link
        t->next = p->next;
        p->next=t;
    }

}

int main()
{
    int A[] = {7,8,9,10,11};
    create(A,5);  // circular link list creation

    Insert(Head,2,77);

    Display(Head);

    return 0;
}
