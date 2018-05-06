#include <vector>
#include <numeric>

using namespace  std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int s = ratings.size();
        if (s == 0) {
            return 0;
        }

        vector<int>  dp(s, 0);
        dp[0] = 1;
        for (int i = 1; i < s; i++) {
            dp[i] = ratings[i] > ratings[i - 1] ? dp[i - 1] + 1 : 1;
        }

        for (int i = s - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && dp[i] <= dp[i + 1]) {
                dp[i] = dp[i + 1] + 1;
            }
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};