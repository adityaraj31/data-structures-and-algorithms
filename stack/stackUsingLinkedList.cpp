#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL; // top of the stack

void push(int x) {
    Node* newNode = new Node();
    newNode -> data = x;
    newNode -> next = top;
    top = newNode;
}

void pop() {
    if(top == NULL) {
        cout << "Stack is underflow\n";
        return ;
    }
    
    Node* temp = top;
    top = top -> next;
    delete temp;
}

int peek() {
    if(top == NULL) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top -> data;
}

bool isEmpty() {
    return top == NULL;
}

int main() {

    push(10);
    push(20);
    push(30);

    cout << "Top element: " << peek() << endl;

    pop();
    cout << "Top element after pop: " << peek() << endl;

    pop();
    pop();

    if(isEmpty()) {
        cout << "Stack is empty";
    }

    return 0;
}