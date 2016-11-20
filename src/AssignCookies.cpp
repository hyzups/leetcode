/*
 * Source URL: https://leetcode.com/problems/assign-cookies/
 */

#include <vector>
#include <algorithm>
#include <functional>

using  namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int i = 0, j = 0;
        int res = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                res++;
                j++;
                i++;
            }
            else {
                i++;
            }
        }

        return res;
    }
};
