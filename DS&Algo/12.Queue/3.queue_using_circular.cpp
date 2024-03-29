#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int Rear;
    int *Q;
};


void Intialize(struct Queue *q, int size)
{
    q->size = size;
    q->front =q->Rear=0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}


void enqueue(struct Queue *q, int x)
{
    //first check if Queue is already full..
    if( (q->Rear + 1) % q->size == q->front)
        {
            printf("Queue is Alraey Full\n");
        }
    else
        {
            q->Rear = (q->Rear + 1) % q->size;
            q->Q[q->Rear] = x;
        }
}


int dequeue(struct Queue *q)
{
    int x = -1;
    //first check if Queue is not already Empty..
    if(q->front == q->Rear)
        {
            printf("Queue is empty\n");
        }
    else
        {
            //increase front using mod operation
            q->front = (q->front + 1) % q->size;
            x = q-> Q[q->front];
        }
    return x;
}


void Display(struct Queue q)
{
    printf("Front index: %d\n", q.front);
    printf("Rear index: %d\n", q.Rear);
    for(int i=q.front+1; i != (q.Rear+1)% q.size; i=(i+1)%q.size)
        {
            printf("Queue element at position %d: %d\n", i, q.Q[i]);
        }
    printf("\n");
}


int main(){

    //create a queue obj
    struct Queue queue;

    //for intialization call create fun
    Intialize(&queue, 10);

    //function for enqueue and dequeue
    enqueue(&queue, 19);
    // enqueue(&queue, 20);
    // enqueue(&queue, 21);
    // enqueue(&queue, 22);
    // enqueue(&queue, 23);

    Display(queue);

    //cll dequeue
    printf("Removed value: %d\n", dequeue(&queue));
    printf("Removed value: %d\n", dequeue(&queue));
    printf("Display 2nd time-after dequeue:\n");
    Display(queue);


    return 0;
}
