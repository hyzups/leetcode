#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        vector<vector<int>> breaks(len, vector<int>());
        vector<bool> dp(len, false);

        for (int i = 0; i < len; i++) {
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                breaks[0].push_back(i);
                dp[i] = true;
            }

            for (int j = 1; j <= i; j++) {
                if (dp[j - 1] && wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()) {
                    breaks[j].push_back(i);
                    dp[i] = true;
                }
            }
        }

        vector<string> res;
        vector<string> curr;

        if (dp[len - 1]) {
            buildString(s, 0, breaks, curr, res);
        }
        return res;
    }

    void buildString(string &s, int pos, vector<vector<int>> &breaks, vector<string> &curr, vector<string> &res) {
        if (pos == s.length())
        {
            string tmp;
            for (int i = 0; i < curr.size(); i++) {
                tmp.append(curr[i]);
                tmp.append(" ");
            }
            
            tmp.erase(tmp.end() - 1);
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < breaks[pos].size(); i++) {
            curr.push_back(s.substr(pos, breaks[pos][i] - pos + 1));
            buildString(s, breaks[pos][i] + 1, breaks, curr, res);
            curr.pop_back();
        }
    }
};