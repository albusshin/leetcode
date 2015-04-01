#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> minstk;
public:
    void push(int x) {
        stk.push(x);
        if (minstk.empty() || x <= minstk.top()) minstk.push(x);
    }

    void pop() {
        if (stk.top() == minstk.top()) minstk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};