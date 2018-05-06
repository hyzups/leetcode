#include <vector>
#include <algorithm>

using namespace  std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int l = coins.size();

        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < l; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount];
    }
};