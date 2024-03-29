#include <stdio.h>
#include <stdlib.h> //for malloc

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
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

char pop()
{
    struct Node *t;
    char x=-1;
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
        printf("Value left in Stack: %c\n", p->data);
    }
    // or
    // while(p != NULL){printf("Value: %d\n", p->data);p=p->next};
}

int isBalanced(char *exp)
{
    int i;

    for(i=0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
            {
                push(exp[i]);
            }
        else if (exp[i] == ')')
            {
                //before calling pop always check Stack..
                if (top == NULL)
                    {
                        return 0; //0 - false
                    }
                pop();
            }
    }
    //check if Stack is Empty..
    if(top == NULL)
        return 1; //True
    else
        return 0; //False
};

int main()
{
    char *exp = "((a+b)*(c-d))";
    printf("is-Balnaced : %d\n", isBalanced(exp));
    Display();

    return 0;
}
