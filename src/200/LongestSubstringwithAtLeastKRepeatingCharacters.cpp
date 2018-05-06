#include <vector>
#include <string> 
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {

        int res = 0;
        int start = 0;

        while (start < s.length()) {

            if (s.length() - start < k) {
                break;
            }

            int mask = 0;
            int nextStart = start;
            vector<int> counts(26, 0);

            for (int i = start; i < s.length(); i++) {
                int index = s[i] - 'a';
                if (counts[index] == 0) {
                    mask |= 1 << index;
                }
                counts[index]++;
                if (counts[index] >= k) {
                    mask &= ~(1 << index);
                }
                if (!mask) {
                    res = max(res, i - start + 1);
                    nextStart = i + 1;
                }
            }
            start = nextStart;
        }

        return res;
    }
};
