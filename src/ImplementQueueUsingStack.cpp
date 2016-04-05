#include <stack> 
#include <vector> 
#include <algorithm>

using namespace std;

class Queue {
private:
    stack<int> _inStack, _outStack;
public:
    // Push element x to the back of queue.
    void push(int x) {
        _inStack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!this->empty()) {
            if (_outStack.empty()) {
                while (!_inStack.empty()) {
                    _outStack.push(_inStack.top());
                    _inStack.pop();
                }
            }
            _outStack.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (!this->empty()) {
            if (_outStack.empty()) {
                while (!_inStack.empty()) {
                    _outStack.push(_inStack.top());
                    _inStack.pop();
                }
            }
            return _outStack.top();
        }
        return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return !_inStack.empty() && !_outStack.empty();
    }
};