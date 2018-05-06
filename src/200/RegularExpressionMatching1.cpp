#include <string>
#include <vector> 
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));

        dp[0][0] = true;

        for (int i = 2; i <= pLen; i++) {
            dp[0][i] = dp[0][i - 2];
        }

        for (int i = 1; i <= sLen; i++) {
            for (int j = 1; j <= pLen; j++) {
                if (p[j - 1] != '*') {
                    dp[i][j] = (s[i - 1] == s[j - 1] || s[j - 1] == '.') && dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] == dp[i][j - 2];
                    if (s[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[sLen][pLen];
    }
};