/// Source URL: https://leetcode.com/problems/combination-sum-iii/

#include <vector> 
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        combinationSum3(res, curr, 1, k, n);
        return res;
    }

    void combinationSum3(vector<vector<int>> &res, vector<int> &curr, int pos, int k, int n) {
        if (k == 0) {
            if (n == 0) {
                res.push_back(curr);
            }
            return;
        }

        if (n < pos) {
            return;
        }

        for (int i = pos; i <= 9; i++) {
            curr.push_back(i);
            combinationSum3(res, curr, i + 1, k - 1, n - i);
            curr.pop_back();
        }
    }
};