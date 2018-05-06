/// Source URL: https://leetcode.com/problems/burst-balloons/

#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));

        for (int k = 2; k < len + 2; k++) {
            for (int left = 0; left + k < len + 2; left++) {
                int right = left + k;
                for (int j = left + 1; j < right; j++) {
                    dp[left][right] = max(dp[left][right], dp[left][j] + dp[j][right] + nums[left] * nums[right] * nums[j]);
                }
            }
        }

        return dp[0][len + 1];
    }
};

