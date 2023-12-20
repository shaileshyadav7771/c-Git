#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    //create a first Node
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last = first; //last is also pointing on first node

    //now with the help of last ptr we can create rest of Node..
    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }

}

// To display the values
void Display(struct Node *p)
{
    while(p) //while p is not NULL
    {
        cout << "Data: " << p->data << ", Address: " << p << ", Next Address: " << p->next << endl;
        cout << "Data: " << p->data << ", Address: " << p << ", Previous Address: " << p->prev << endl;
        p=p->next;
    }
    printf("\n");
}

// To find Length
int Length(struct Node *p)
{
    int length=0;
    while(p) //while p is not NULL
    {
        length++;
        p=p->next;
    }
    return length;
}

//Insert a new node
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > Length(p))
    {
        return;
    }

    if(index == 0) //before first Node
    {
        //create new node
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x; // add data
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        //move first ptr
        first=t;
    }
    else
    {
        //we need to move ptr to the (pos -1)
        for(i=0; i<index-1; i++)
        {
            p=p->next;
        }
        // create new node
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=x;

        t->prev=p;
        t->next=p->next;

        if (p->next != NULL)
        {
            //special case will run if not last node
            p->next->prev=t;
        }
        p->next=t;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50, 60,};
    create(A,6);
    printf("\nLength is %d\n", Length(first));
    Insert(first,6,7771);

    Display(first);

    return 0;
}
