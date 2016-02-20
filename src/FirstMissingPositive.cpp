/// Source: https://leetcode.com/problems/first-missing-positive/

#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i] - 1) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n;
    }
};