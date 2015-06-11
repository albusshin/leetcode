class Stack {
    queue<int> q1, q2;
    int stktop;
    int size;
public:
    Stack() {
        size = 0;
        stktop = 0;
    }
    
    // Push element x onto stack.
    void push(int x) {
        if (size == 0) q1.push(x);
        else {
            if (q1.empty()) q2.push(x);
            else q1.push(x);
        }
        stktop = x;
        size++;
    }

    // Removes the element on top of the stack.
    void pop() {
        if (size == 0) return;
        else {
            queue<int> *fromq, *toq;
            if (q1.empty()) {
                fromq = &q2;
                toq = &q1;
            }
            else {
                fromq = &q1;
                toq = &q2;
            }
            for (int i = 0; i < size - 1; i++) {
                toq->push(fromq->front());
                if (i == size - 2) stktop = toq->front();
                fromq->pop();
            }
            fromq->pop();
            size--;
        }
    }

    // Get the top element.
    int top() {
        return this->stktop;
    }

    // Return whether the stack is empty.
    bool empty() {
        return this->size == 0;
    }
};