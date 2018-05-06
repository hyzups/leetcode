#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();

        vector<vector<bool>> isPalin(len, vector<bool>(len, false));

        for (int i = 0; i < len; i++) {
            isPalin[i][i] = true;
        }

        for (int k = 1; k < len; k++) {
            for (int i = 0; i + k < len; i++) {
                isPalin[i][i + k] = (s[i] == s[i + k]) && (k == 1 || isPalin[i + 1][i + k - 1]);
            }
        }

        vector<vector<string>> res;
        vector<string> curr;
        buildPartitions(0, s, isPalin, res, curr, len);
        return res;
    }

    void buildPartitions(int pos, string &s, vector<vector<bool>> &isPalin, vector<vector<string>> &res, vector<string> &curr, int len) {
        if (pos == len) {
            res.push_back(curr);
            return;
        }

        for (int i = pos; i < len; i++) {
            if (isPalin[pos][i]) {
                string part = s.substr(pos, i - pos + 1);
                curr.push_back(part);
                buildPartitions(i + 1, s, isPalin, res, curr, len);
                curr.pop_back();
            }
        }
    }
};