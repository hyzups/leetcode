#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;

public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxQueue.size() == minQueue.size()) {
            if (maxQueue.size() == 0) {
                maxQueue.push(num);
            }
            else {
                if (num <= minQueue.top()) {
                    maxQueue.push(num);
                }
                else {
                    int temp = minQueue.top();
                    minQueue.pop();
                    minQueue.push(num);
                    maxQueue.push(temp);
                }
            }
        }
        else {
            if (num >= maxQueue.top()) {
                minQueue.push(num);
            }
            else {
                int temp = maxQueue.top();
                maxQueue.pop();
                maxQueue.push(num);
                minQueue.push(temp);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxQueue.size() != minQueue.size()) {
            return maxQueue.top();
        }
        if (maxQueue.size() != 0) {
            return ((double)maxQueue.top() + (double)minQueue.top()) / 2;
        }
        return 0.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();