#include<iostream>
using namespace std;

#define MAX_SIZE 1000

int queue[MAX_SIZE];

int front = 0, rear = -1;

void enqueue(int x) {
    if(rear == MAX_SIZE - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    queue[++rear] = x;
}

void dequeue() {
    if(front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    front++;
}

int getFront() {
    if(front > rear) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue[front];
}

bool isEmpty() {
    return front > rear;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Front element: " << getFront() << endl;
    dequeue();

    cout << "Front element after dequeue: " << getFront() << endl;
    dequeue();
    dequeue();

    if(isEmpty()) {
        cout << "Queue is empty\n";
    }

    return 0;
} 