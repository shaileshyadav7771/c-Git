#include <stdio.h>
#include <stdlib.h> //for malloc

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    //create a node and make t point on it.
    t = (struct Node *)malloc(sizeof(struct Node));

    //first check if Stack is full..
    if(t==NULL)
    {
        printf("Stack is Full!\n");
    }
    else
    {
        //otherwisse Insert a Node..
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    //first check if already empty :)
    if(top == NULL)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        // we delet with the help of temp t ptr
        t = top;
        top = top->next;
        x= t->data;
        free(t);
    }
    return x;
}

void Display()
{
    // we need temp pointer p to scan
    struct Node *p;
    p = top;
    for (int i=0; p!=NULL; p=p->next)
    {
        printf("Value: %d\n", p->data);
    }
    // or
    // while(p != NULL){printf("Value: %d\n", p->data);p=p->next};
}



int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    Display();

    printf("Pop-out value : %d\n",pop());

    Display();

    return 0;
}
