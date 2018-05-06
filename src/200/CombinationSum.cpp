#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        combinationSum(candidates, 0, curr, res, target);

        return res;
    }

private:
    void combinationSum(vector<int> &candidates, int pos, vector<int> &curr, vector<vector<int>> &res, int target) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 || pos == candidates.size()) {
            return;
        }

        curr.push_back(candidates[pos]);
        combinationSum(candidates, pos, curr, res, target - candidates[pos]);
        curr.pop_back();
        combinationSum(candidates, pos + 1, curr, res, target);
    }
};