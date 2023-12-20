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

/// Recursive Display
void RecursiveDisplay(struct Node *head)
{
    static int flag = 0;
    if (head!=Head || flag==0)
    {
        flag = 1;
        cout << "Data Recursive: " << head->data << ", Address: " << head << ", Next Address: " << head->next << endl;
        RecursiveDisplay(head->next);
    }
    flag=0;
}


int main()
{
    int A[] = {7,8,9,10,11};
    create(A,5);  // circular link list creation
    Display(Head);
    RecursiveDisplay(Head);

    return 0;
}




