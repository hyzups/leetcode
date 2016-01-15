#include<vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> counts(26, 0);
        vector<bool> added(26, false);
        string res;

        for (int i = 0; i < s.length(); i++) {
            counts[s[i] - 'a']++;
        }

        for (char c : s) {
            counts[c - 'a']--;
            if (res.empty()) {
                res.push_back(c);
                added[c - 'a'] = true;
            }
            else if (added[c - 'a']) {
                continue;
            }
            else {
                while (!res.empty() && c < res.back() && counts[res.back() - 'a'] > 0) {
                    added[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                added[c - 'a'] = true;
            }
        }
        return res;
    }
};
