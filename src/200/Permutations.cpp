#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(nums, 0, res);
        return res;
    }

private:
    void permute(vector<int> &nums, int pos, vector<vector<int>> &res)
    {
        if (pos == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            permute(nums, pos + 1, res);
            swap(nums[pos], nums[i]);
        }
    }
};