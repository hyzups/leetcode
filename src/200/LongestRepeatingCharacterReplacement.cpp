#include <string> u
#include <vector> 
#include <algorithm> 

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> counts(26, 0);
        int maxCharCounts = 0;

        int start = 0, end = 0;
        int res = 0;

        while (end < s.length()) {
            char c = s[end] - 'A';
            counts[c]++;
            maxCharCounts = max(maxCharCounts, counts[c]);
            end++;

            while (end - start - maxCharCounts - k > 0) {
                counts[s[start++] - 'A']--;

                for (auto i : counts) {
                    maxCharCounts = max(maxCharCounts, i);
                }
            }

            res = max(res, end - start);
        }
        return res;
    }
};
