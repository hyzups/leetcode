#include <string> 
#include <vector> 

using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {

        int tLen = t.length();
        int sLen = s.length();

        vector<vector<int>> dp(sLen + 1, vector<int>(tLen + 1));

        for (int i = 1; i <= tLen; i++) {
            dp[0][i] = 0;
        }

        for (int i = 0; i <= sLen; i++) {
            dp[i][0] = 1; 
        }

        for (int i = 1; i <= sLen; i++) {
            for (int j = 1; j <= tLen; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[sLen][tLen];
    }
};
