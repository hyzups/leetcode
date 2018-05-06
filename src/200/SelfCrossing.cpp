/// Source URL: https://leetcode.com/problems/self-crossing/

#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& nums) {
        for (size_t i = 3; i < nums.size(); i++) {
            if (nums[i - 1] <= nums[i - 3] && nums[i] >= nums[i - 2]) {
                return true;
            }
            if (i > 3 && (nums[i - 1] == nums[i - 3] && nums[i] + nums[i - 2] >= nums[i - 4])) {
                return true;
            }
            if (i > 4
                && nums[i-2] - nums[i-4] >= 0
                && nums[i] + nums[i - 4] >= nums[i - 2] 
                && nums[i-5] + nums[i-3] >= nums[i-1] 
                && nums[i-3] <= nums[i-1] + nums[i-5]) {
                return true;
            }
        }
        return false;
    }
};