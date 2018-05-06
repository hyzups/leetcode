#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }

        int maxSoFar = 0, minSoFar = 0, res = 0;

        for (int i = 0; i < len; i++) {
            if (nums[i] < 0) {
                swap(maxSoFar, minSoFar);
                maxSoFar = max(nums[i], nums[i] * maxSoFar);
                minSoFar = min(nums[i], nums[i] * minSoFar);
                res = max(res, maxSoFar);
            }
        }

        return res;
    }
};