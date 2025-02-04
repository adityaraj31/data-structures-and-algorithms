#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;

public:
    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front()); // Fix: Use front() before pop()
            q1.pop();
        }
        q1.push(x); // Push new element

        while (!q2.empty()) {
            q1.push(q2.front()); // Fix: Use front() before pop()
            q2.pop();
        }
    }

    int pop() {
        if (q1.empty()) { // Handle empty stack
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        if (q1.empty()) { // Handle empty stack
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack s;
    s.push(10);
    s.push(20);

    cout << s.top() << endl; // Should print 20

    s.pop();
    cout << s.top() << endl; // Should print 10

    return 0;
}
