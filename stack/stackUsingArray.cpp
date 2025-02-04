#include<iostream>
using namespace std;

#define MAX_SIZE 1000

int stack[MAX_SIZE];

int top = -1;

void push(int x) {
    if(top == MAX_SIZE - 1) {
        cout << "Stack Overflow\n";
        return ;
    }
    top++;
    stack[top] = x;
}

void pop() {
    if(top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    top--;
}

int peek() {
    if(top == -1) {
        cout << "Stack is empty";
        return -1;
    }
    return stack[top];
}

bool isEmpty() {
    return top == -1;
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
        cout << "Stack is empty" << endl;
    }

    return 0;

}