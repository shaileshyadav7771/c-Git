#include <iostream>
using namespace std;

class DEQueue {
private:
    int front; // Front index of the DEQueue
    int rear;  // Rear index of the DEQueue
    int size;  // Maximum size of the DEQueue
    int* Q;    // Pointer to the DEQueue array

public:
    // Constructor Definition
    DEQueue(int size);

    // Destructor Definition
    ~DEQueue();

    // Displays the elements of the DEQueue
    void display();

    // Enqueues an element at the front of the DEQueue
    void enqueueFront(int x);

    // Enqueues an element at the rear of the DEQueue
    void enqueueRear(int x);

    // Dequeues an element from the front of the DEQueue
    int dequeueFront();

    // Dequeues an element from the rear of the DEQueue
    int dequeueRear();

    // Checks if the DEQueue is empty
    bool isEmpty();

    // Checks if the DEQueue is full
    bool isFull();
};

// Constructor Definition
DEQueue::DEQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
}

// Destructor Definition
DEQueue::~DEQueue() {
    delete[] Q;
}

// Checks if the DEQueue is empty
bool DEQueue::isEmpty() {
    return front == -1;
}

// Checks if the DEQueue is full
bool DEQueue::isFull() {
    return (rear == size - 1 && front == 0) || (rear == front - 1);
}

// Enqueues an element at the front of the DEQueue
void DEQueue::enqueueFront(int x) {
    if (isFull()) {
        cout << "DEQueue Overflow" << endl;
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        Q[front] = x;
    }
}

// Enqueues an element at the rear of the DEQueue
void DEQueue::enqueueRear(int x) {
    if (isFull()) {
        cout << "DEQueue Overflow" << endl;
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        Q[rear] = x;
    }
}

// Dequeues an element from the front of the DEQueue
int DEQueue::dequeueFront() {
    if (isEmpty()) {
        cout << "DEQueue Underflow" << endl;
        return -1;
    } else {
        int x = Q[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return x;
    }
}

// Dequeues an element from the rear of the DEQueue
int DEQueue::dequeueRear() {
    if (isEmpty()) {
        cout << "DEQueue Underflow" << endl;
        return -1;
    } else {
        int x = Q[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
        return x;
    }
}

// Displays the elements of the DEQueue
void DEQueue::display() {
    if (isEmpty()) {
        cout << "DEQueue is Empty" << endl;
    } else {
        cout << "DEQueue Elements: ";
        int i = front;
        while (true) {
            cout << Q[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};

    DEQueue deq(sizeof(A)/sizeof(A[0]) + sizeof(B)/sizeof(B[0]) + 1); // Extra space for the additional elements

    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++) {
        deq.enqueueRear(A[i]);
    }
    deq.display();

    deq.enqueueRear(11); // Trying to enqueue beyond the capacity

    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++) {
        deq.dequeueFront();
    }
    deq.dequeueFront(); // Trying to dequeue when queue is empty

    for (int i = 0; i < sizeof(B)/sizeof(B[0]); i++) {
        deq.enqueueFront(B[i]);
    }
    deq.display();

    deq.enqueueFront(10); // Enqueuing beyond the capacity
    deq.enqueueFront(12); // Enqueuing beyond the capacity

    for (int i = 0; i < sizeof(B)/sizeof(B[0]); i++) {
        deq.dequeueRear();
    }
    deq.display();

    deq.dequeueRear(); // Trying to dequeue when queue is empty
    deq.dequeueRear(); // Trying to dequeue when queue is empty

    return 0;
}
