#include <stack> 
using namespace std;

class MinStack {
private:
    stack<int> stk;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }

    void push(int x) {
        if (stk.empty()) {
            stk.push(0);
            min = x;
        }
        else {
            stk.push(x - min);
            if (stk.top() < min) {
                min = x;
            }
        }
    }

    void pop() {
        if (!stk.empty()) {
            int res = stk.top();
            if (res < 0) {
                min -= res;
            }
            stk.pop();
        }
    }

    int top() {
        if (!stk.empty()) {
            return stk.top() + min;
        }
    }

    int getMin() {
        return min;
    }
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/