#include <vector>
#include <deque> 

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;

        deque<pair<int, int> > mq;

        for (int i = 0; i < nums.size(); i++) {
            if (!mq.empty() && i - mq.front().second + 1 > k) {
                mq.pop_front();
            }

            while (!mq.empty() && nums[i] >= mq.back().first) {
                mq.pop_back();
            }
            mq.emplace_back(nums[i], i);

            if (i >= k - 1) {
                res.push_back(mq.front().first);
            }
        }

        return res;
    }
};