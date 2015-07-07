class Queue {
    stack<int> pushed, poped;
    
    void pour(stack<int>& p1, stack<int>& p2) {
        while (!p1.empty()) {
            p2.push(p1.top());
            p1.pop();
        }
    }
    
public:
    // Push element x to the back of queue.
    void push(int x) {
        if (pushed.empty()) pour(poped, pushed);
        pushed.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (poped.empty()) pour(pushed, poped);
        poped.pop();
    }

    // Get the front element.
    int peek(void) {
        if (poped.empty()) pour(pushed, poped);
        return poped.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return pushed.empty() && poped.empty();
    }
};