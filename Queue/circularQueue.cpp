#include<iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int k) {
        capacity = k;
        arr = new int(k);
        front = -1;
        rear = -1;
    }

    bool enqueue(int x) {
        if(isFull()) return false;
        if(front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        return true;
    }

    bool dequeue() {
        if(isEmpty()) return false;
        if(front == rear) front = rear = -1;
        else front = (front + 1) % capacity;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }

    int getRear() {
        return isEmpty() ? -1 : arr[rear];
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

};

int main() {
    CircularQueue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.getFront() << endl;
    q.enqueue(40);
    cout << "Rear element: " << q.getRear() << endl;

    return 0;
}