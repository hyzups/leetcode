/// Source URL: https://leetcode.com/problems/contains-duplicate-ii/

#include <unordered_set>
#include <vector> 

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return false;
            }
            s.insert(nums[i]);
            if (i - k + 1 >= 0) {
                s.erase(nums[i - k + 1]);
            }
        }
        return true;
    }
};

