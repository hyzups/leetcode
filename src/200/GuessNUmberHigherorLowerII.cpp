#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int k = 1; k < n; k++) {
            for (int i = 1; i < n - k; i++) {
                dp[i][i + k] = INT_MAX;
                for (int j = i; j <= i + k; j++) {
                    dp[i][i + k] = min(dp[i][i + k], j + max((j + 1 <= i + k ? dp[j + 1][i + k] : 0), (j - 1 >= i ? dp[i][j - 1] : 0)));
                }
            }
        }

        return dp[1][n];
    }
};

//int main()
//{
//
//    Solution s;
//    s.getMoneyAmount(3);
//}
