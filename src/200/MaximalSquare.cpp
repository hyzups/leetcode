/// Source URL: https://leetcode.com/problems/maximal-square/

#include <vector> 
#include <algorithm> 

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return 0;
        }

        vector<int> dp(col, 0);

        int res = 0;

        for (int i = 0; i < row; i++) {
            for (int j = col - 1; j >= 0; j--) {
                if (i = 0) {
                    dp[j] = matrix[0][j] - '0';
                    res = max(dp[j], res);
                }
                else {
                    if (matrix[i][j] == '0') {
                        dp[j] = 0;
                    }
                    else {
                        int len = j > 0 ? dp[j - 1] : 0;
                        int k = 0;
                        for (k = 0; k < len; k++) {
                            if (matrix[i][j - k - 1] != '1' || matrix[i - k - 1][j] != '1') {
                                break;
                            }
                        }
                        len = k + 1;
                        dp[j] = len;
                        res = max(res, len * len);
                    }
                }
            }
        }

        return res *res;

    }
};