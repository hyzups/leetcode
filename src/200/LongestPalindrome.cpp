#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> counts(100, 0);
        for (auto c : s) {
            counts[c - 'A']++;
        }
        int res = 0;
        for (auto i : counts) {
            res += i & 1 ? i - 1 : i;
        }
        return res < s.length() ? res + 1 : res;
    }
};
