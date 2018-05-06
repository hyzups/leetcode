#include <vector> 
#include <algorithm>

using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int row = dungeon.size();
        if (row < 1) {
            return 0;
        }
        int col = dungeon[0].size();
        if (col < 1) {
            return 0;
        }

        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (i == row - 1 && j == col - 1) {
                    dp[row - 1][col - 1] = max(1, 1 - dungeon[row - 1][col - 1]);
                }
                else if (i == row - 1) {
                    dp[i][j] = max(1, dp[i][j + 1] - dungeon[i][j]);
                }
                else if (j == col - 1) {
                    dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
                }
                else {
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
                }
            }
        }

        return dp[0][0];
    }
};