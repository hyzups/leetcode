#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts(26, 0);
        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }

        for (auto num : counts) {
            if (num != 0) {
                return false;
            }
        }

        return true;
    }
};