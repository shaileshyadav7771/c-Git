#include <stdio.h>
#include <stdlib.h> //for malloc

struct Stack
{
    int Size;
    int Top;
    int *S;
};

void create(struct Stack *st) // call by refernce need to change/modify
{
    printf("Enter Size : ");
    scanf("%d", &st->Size);
    st->Top = -1;
    //create a an array
    st ->S = (int *)malloc(st->Size*sizeof(int));
}

void Display(struct Stack st) // call by value just read
{
    for (int i = st.Top; i>=0; i--)
    {
        printf(" value in Stack : %d ", st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    //before insert check if Stack is full
    if (st->Top == st->Size-1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        //change Top pointer and push value to it..
        st->Top++;
        st->S[st->Top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    // before delete just check Stack is not empty
    if (st->Top == -1)
    {
        printf("Stack is empty-underflow");
    }
    else
    {
        x = st->S[st->Top--];
    }
    return x;
}

int peek(struct Stack st,int index)
{
    int x=-1;
    if (st.Top-index+1<0)
        printf("Invalid Index \n");
    x=st.S[st.Top-index+1];
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.Top == -1)
        return 1;  //in C 1 True
    return 0;
}

int isFull(struct Stack st)
{
    return st.Top == st.Size-1;
}

//to get top most element in stack
int stackTop(struct Stack st)
{
    //before directreturn first check if stack is not empty.
    if (!isEmpty == 0)
        return st.S[st.Top];
    return -1; // non top element(means stack is Empty)
}

int main()
{
    //create a obj of Stack struct
    struct Stack st;

    create(&st); //passing address of st
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    printf("Peek : %d\n", peek(st, 1));
    printf("Peek : %d\n", peek(st, 3));

    Display(st);
    return 0;
}
