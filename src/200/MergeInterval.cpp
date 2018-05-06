#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) -> bool {
            return a.start == b.start ? a.end <= b.end : a.start < b.start;
        });

        vector<Interval> res; 

        if (intervals.size() == 0) {
            return res;
        }

        Interval curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (curr.end < intervals[i].start) {
                res.push_back(curr); 
                curr = intervals[i];
            }
            else {
                curr.end = max(curr.end, intervals[i].end);
            }
        }
        res.push_back(curr);

        return res;
    }
};