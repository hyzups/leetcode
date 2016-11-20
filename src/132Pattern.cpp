/*
 * URL: https://leetcode.com/problems/132-pattern/
 */

#include<vector>
#include<algorithm>
#include<numeric>
#include<cctype>
#include<stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int lastNum = INT_MIN;
        stack<int> s;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < lastNum) {
                return true;
            }

            while (!s.empty() && nums[i] > s.top()) {
                lastNum = s.top();
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};
