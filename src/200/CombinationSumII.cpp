#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);

        vector<vector<int>> res;
        vector<int> curr;

        comSum2(candidates, 0, curr, res, target, used);
        return res;
    }

    void comSum2(vector<int> &cand, int pos, vector<int> &curr, vector<vector<int>> &res, int target, vector<bool> &used) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 || pos == cand.size()) {
            return;
        }

        if (pos == 0 || cand[pos] != cand[pos - 1] || used[pos - 1]) {
            curr.push_back(cand[pos]);
            used[pos] = true;
            comSum2(cand, pos + 1, curr, res, target - cand[pos], used);
            curr.pop_back();
            used[pos] = false;
        }

        comSum2(cand, pos + 1, curr, res, target, used);
    }

};