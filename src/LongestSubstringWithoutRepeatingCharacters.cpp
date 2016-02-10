#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> nums(256, 0);

        int l = 0; int r = 0;

        int res;

        while (r < s.length()) {
            while (r < s.length() && nums[s[r]] == 0) {
                nums[s[r]] = 1;
                r++;
            }

            res = max(res, r - l);

            while (nums[s[r]] > 0) {
                nums[s[l]]--;
                l++;
            }
        }
        return res;
    }
};