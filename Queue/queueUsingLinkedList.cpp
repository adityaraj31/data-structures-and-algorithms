#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL; // Front pointer
Node* rear = NULL; // Rear pointer

void enqueue(int x) {
    Node* newNode = new Node();
    newNode -> data = x;
    newNode -> next = NULL;

    if(rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear -> next = newNode;
    rear = newNode;
}

void dequeue() {
    if(front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    front = front -> next;

    if(front == NULL) rear = NULL;
    delete temp;
}

int getFront() {
    if(front == NULL) {
        cout << "Queue is empty\n";
        return -1;
    }
    return front -> data;
}

bool isEmpty() {
    return front == NULL;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Front element: " << getFront() << endl;
    dequeue();

    cout << "Front element after dequeue: " << getFront() << endl;
    dequeue();

    cout << "Front element after another dequeue: " << getFront() << endl;
    dequeue();

    if(isEmpty()) {
        cout << "Queue is empty\n";
    }

    return 0;
}