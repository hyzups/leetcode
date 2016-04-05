#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        permuteUniqueRe(res, nums, 0);
    }

    void permuteUniqueRe(vector<vector<int>> &res, vector<int> &nums, int pos)
    {
        if (pos == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = pos; i < res.size(); i++) {
            if (i != pos && nums[i] == nums[pos]) {
                continue;
            }
            swap(nums[i], nums[pos]);
            permuteUniqueRe(res, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }
};