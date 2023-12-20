#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        //non-parameterized constructor no size for Stack top is NULL intially
        Stack(){top = NULL;}
        void push(int x);
        int pop();
        void Display();
};

//--------------Implementation------------------------------
void Stack::push(int x)
{
    //create a new node using temp t
    Node *t=new Node;
    if (t==NULL)
        cout << "Stack is Full.." << endl;
    else
    {
        t->data=x;
        t->next=top;
        top = t;
    }
}

int Stack::pop()
{
    int x =-1;
    if (top==NULL)
        cout << "Stack is Empty.." << endl;
    else
    {
        x=top->data;
        Node *t = top;
        top=top->next;
        delete t;
    }
    return x;
}

void Stack::Display()
{
    Node *p = top;
    while(p!=NULL)
    {
        cout << "Data is: " << p->data << endl;
        p=p->next;
    }
    cout << endl;
}


int main()
{
    //creat an obj of class
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.Display();
    cout << "Poping-out value :" << stk.pop() <<endl;
    stk.Display();

    return 0;
}
