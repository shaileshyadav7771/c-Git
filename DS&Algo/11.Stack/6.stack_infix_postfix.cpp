#include <iostream>
#include<cstring>

using namespace std;

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

int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '\\')
        return 2;
    return 0;
}


int isOperand(char x)
{
    if(x=='+' || x == '-' || x == '*' || x == '\\')
        return 0; //False
    else
        return 1; //True
}


char * Infix_to_posfix(char *infix)
{
    char *postfix;
    //need to create memory to store conversion postfix result..
    int len = strlen(infix);
    postfix = (char *)malloc((len+2)*sizeof(char)); //one extra space for storing \0
    int i = 0, j = 0;

    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            {
                postfix[j++] = infix[i++];
            }
        else
        {
            //means not operand then let us check precedence ..
            if (top == NULL || precedence(infix[i]) > precedence(top->data))
            {
                //means push it into postfix stack and increase j value
                push(infix[i++]);
            }
            else
            {
                //pop-out value and add it to PostFix string..
                postfix[j++] = pop();
            }
        }
    }
    while(top != NULL)
    {
        //Add all remaining value inside Stack..
        while(top != NULL)
        {
            postfix[j++] = pop();
        }
    }
    //at last add NULL char to become it complete str
    postfix[j] = '\0';
    return postfix;
}


int main() {

    char *infix = "a+b*c";
    // push('#');
    char *postfix = Infix_to_posfix(infix);
    printf("posfix : %s\n", postfix);

    int length = strlen(postfix);  // Calculate string length
    printf("Postfix expression: legnth %d\n", length);
    for (int i = 0; i <= length; i++) {
        if (postfix[i] == '\0') {
            printf("\\0 ");
        } else {
            printf("%c ", postfix[i]);
        }
    }
    // Free the memory allocated for 'postfix'
    free(postfix);
    return 0;
}
