#include<iostream>
#include<stack>
using namespace std;

class Queue {
public:
    stack<int> s1;
    stack<int> s2;

    void push(int data) {
        s1.push(data);
    }

    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    int peek() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Peek: " << q.peek() << endl;  // Should print 10
    cout << "Pop: " << q.pop() << endl;    // Should print 10
    cout << "Pop: " << q.pop() << endl;    // Should print 20
    cout << "Peek: " << q.peek() << endl;  // Should print 30
    cout << "Pop: " << q.pop() << endl;    // Should print 30
    cout << "Is Queue Empty: " << q.empty() << endl;  // Should print 1 (true)

    return 0;
}
