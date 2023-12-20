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
int Delete(struct Node *p, int index)
{
    int x=-1,i;

    if (index < 1 || index > Length(p))
    {
        return -1;
    }
    //if index=1 special case
    if (index==1)
    {
        first = first->next;
        //if first is not NULL(means not a s/g node)
        if (first)
        {
            first->prev = NULL;
        }
        //take data from using P
        x=p->data;
        free(p);
    }
    // if not the first node reach to index
    else
    {
        for(i=0; i<index-1; i++)
        {
            p=p->next;
        }
        //modify the links
        p->prev->next = p->next;
        //now need to be careful
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        //take data in x and delete node..
        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50, 60,};
    create(A,6);
    printf("\nLength is %d\n", Length(first));
    //delete 2nd node
    Delete(first, 2);
    Display(first);

    return 0;
}
