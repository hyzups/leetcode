#include <vector> 
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.length() < p.length() || s.length() == 0) {
            return res;
        }
        vector<int> counts(26, 0);
        for (auto c : p) {
            counts[c - 'a']++;
        }

        int right = 0, left = 0, total = p.length();
        while (right < s.length()) {
            if (counts[s[right++] - 'a']-- > 0)  total--;

            if (total == 0) {
                res.push_back(left);
            }

            if (right - left > p.length() && counts[s[left++] - 'a']++ >= 0) total++;
        }
        return res;

    }
};