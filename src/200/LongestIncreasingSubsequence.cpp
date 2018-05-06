#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int INF = 100000000;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        vector<int> lis(nums.size(), INF);

        for (int i = 0; i < nums.size(); i++) {
            *lower_bound(lis.begin(), lis.end(), nums[i]) = nums[i];
        }

        return lower_bound(lis.begin(), lis.end(), INF) - lis.begin();
    }
};