#include <bits/stdc++.h>
using namespace std;
class MinStack {
    stack<int> s, st;
public:
    void push(int val) {
        s.push(val);
        if (st.empty() || val <= st.top()) st.push(val);
    }
    void pop() {
        if (s.top() == st.top()) st.pop();
        s.pop();
    }
    int top() { return s.empty() ? -1 : s.top(); }
    int getMin() { return st.empty() ? -1 : st.top(); }
};

int main(){
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl; // Returns -3
    minStack->pop();
    cout << minStack->top() << endl;    // Returns 0
    cout << minStack->getMin() << endl; // Returns -2
    return 0;
}