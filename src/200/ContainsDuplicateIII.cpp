/// Source URL: https://leetcode.com/problems/contains-duplicate-iii/

#include <vector> 
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }

        set<int> existing;

        for (int i = 0; i < n; i++) {
            if (i > k) {
                existing.erase(nums[i - k - 1]);
            }
            auto pos = existing.lower_bound(nums[i] - t);
            if (pos != existing.end() && *pos - nums[i] <= t) {
                return true;
            }
            existing.insert(nums[i]);
        }

        return false;
    }
};