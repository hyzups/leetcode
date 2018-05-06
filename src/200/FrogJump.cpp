/// Source URL: https://leetcode.com/problems/frog-jump/

#include <vector>
#include <set>
#include <algorithm> 
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, bool> dp;

public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2) {
            return true;
        }
        return canCross(stones, 0, 0);
    }

    bool canCross(vector<int>& stones, int pos, int k) {
        int key = pos | k << 11;
        if (dp.count(key) > 0) {
            return dp[key];
        }

        for (size_t i = pos + 1; i < stones.size(); i++) {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1) continue;
            if (gap > k + 1) {
                return dp[key] = false;
            }
            if (canCross(stones, i, gap)) {
                return dp[key] = true;
            }
        }
        return dp[key] = (pos == stones.size() - 1);
    }
};
