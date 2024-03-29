#include <iostream>
#include<cstring>

using namespace std;

struct Node
{
    int data;   //int data
    struct Node *next;
}*top=NULL;

void push(int x)  //push function will take int..
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

int pop()   //return type int
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


int isOperand(char x)
{
    if(x=='+' || x == '-' || x == '*' || x == '/')
        return 0; //False
    else
        return 1; //True
}

int Eval(char *postfix)
{
    int i=0;
    int x1, x2, r;

    for(i=0; postfix[i]!='\0'; i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2 = pop(); x1 = pop();
            switch(postfix[i])
            {
                case '+':r=x1+x2; break;
                case '-':r=x1-x2; break;
                case '*':r=x1*x2; break;
                case '/':r=x1/x2; break;
            }
            push(r);
        }
    }
    return top->data;
}


int main() {

    char *postfix = "234*+82/-";

    printf("Result is %d\n", Eval(postfix));

    return 0;
}
