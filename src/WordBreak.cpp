#include <string>
#include <vector>
#include <unordered_set>

using namespace  std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        if (len < 1) {
            return true;
        }
        vector<bool> dp(len, false);
        dp[0] = wordDict.find(s.substr(0, 1)) != wordDict.end();

        for (int i = 1; i < len; i++) {
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                dp[i] = true;
                continue;
            }
            for (int j = 1; j <= i; j++) {
                if (dp[j - 1] && wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len - 1];
    }
};