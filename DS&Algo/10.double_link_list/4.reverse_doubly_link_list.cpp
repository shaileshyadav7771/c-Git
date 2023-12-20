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

//Delete the node
void Reverse(struct Node *p)
{
    //for swapping we need one extra poiter
    struct Node *temp;

    while(p!=NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p=p->prev;
        //on new check if it is the last node
        if (p != NULL && p->next == NULL)
        {
            first = p;
        }
    }
}


int main()
{
    int A[] = {10, 20, 30, 40, 50, 60,};
    create(A,6);
    printf("\nLength is %d\n", Length(first));
    Reverse(first);
    Display(first);

    return 0;
}
