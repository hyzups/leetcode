#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> m_normal;
    stack<int> m_min;
public:
    void push(int x) {
        m_normal.push(x);
        if (m_min.empty() || x <= m_min.top()) {
            m_min.push(x);
        }
    }

    void pop() {
        int x = m_normal.top();
        m_normal.pop();
        if (x == m_min.top()) {
            m_min.pop();
        }
    }

    int top() {
        return m_normal.top();
    }

    int getMin() {
        return m_min.top();
    }
};