#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*Rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if(t == NULL)
        {
            printf("Queue is full-can't create a new node");
        }
    else
        {
            //means Node t is already created..
            //just set data and move Rear to current Inserted..
            t->data = x;
            t->next = NULL;

            // check if It's first Node..
            if (front == NULL)
                {
                    // Move front & Rear to current first Node
                    front = Rear = t;
                }
            else
                {
                    //Node alreay there..
                    Rear->next = t;
                    //move Rear to last node after above link
                    Rear = t;
                }
        }
}

int dequeue()
    {
        //return -1 elase the dequeue node data
        int x = -1;
        struct Node *P= front;
        //first check if the node is alraedy empty
        if(front == NULL)
            {
                printf("Queue is alreay Empty .. can not remove Element from queue..");
            }
        else
            {
                // we have some values
                //use temp P on first Node..
                front = front->next;
                x = P->data;
                free(P);
            }
        return x;
    }

void Display()
    {
        struct Node *temp= front;

        while(temp)
            {
                printf("%d\n", temp->data);
                temp= temp->next;
            }
        printf("\n");
    }

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    Display();

    printf("Dequeue : %d\n", dequeue());
    printf("Dequeue : %d\n", dequeue());

    Display();

    return 0;
}
