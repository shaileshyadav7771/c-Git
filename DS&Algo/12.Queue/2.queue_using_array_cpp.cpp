#include <iostream>
using namespace std;

class Queue
{
    private:
        int size;
        int front;
        int Rear;
        int *Q;
    public:
        //non=parameterized constuctor to intsialize
        //So, when no size is explicitly specified, the default size of 10 is used.
        Queue(){front=Rear=-1; size=10; Q=new int[size];}

        //parameterized constuctor to take size
        Queue(int size){front=Rear=-1; this->size=size; Q=new int[this->size];}

        //fn for enqueue
        void enqueue(int x);

        //fn for dequeue
        int dequeue();

        //Display function
        void Display();
};

//outside class implement it ..
void Queue::enqueue(int x)
{
    //In C++, member functions of a class can directly access private members of the class..
    if(Rear == size -1)
        {
            printf("Queue is Full\n");
        }
    else
        {
            Rear++;
            Q[Rear] = x;
        }
}

int Queue::dequeue()
{
    int x=-1;
    if (front == Rear)
        {
            printf("Queue is already Empty\n");
        }
    else
        {
            front++;
            x = Q[front];
        }
    return x;
}


void Queue::Display()
{
    for (int i = front+1; i <=Rear; i++)
        {
            printf("Queue element at position %d: %d\n", i, Q[i]);
        }
    printf("\n");
}


int main()
{
    Queue q(10);
    q.enqueue(77);
    q.enqueue(88);
    q.enqueue(99);
    q.enqueue(111);

    q.Display();

    q.dequeue();
    printf("------Display after Dequeue -----\n");
    q.Display();

    return 0;
}
