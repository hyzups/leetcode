#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return nums;
        }

        sort(nums.begin(), nums.end());

        int maxLen = 0;
        int start = 0;
        vector<int> dp(len, 1);
        vector<int> parent(len, -1);

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > maxLen) {
                        start = i;
                    }
                }
            }
        }

        vector<int> res;
        while (start >= 0) {
            res.push_back(nums[start]);
            start = parent[start];
        }
        return res;
    }
};