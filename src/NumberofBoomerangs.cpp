/*
 * URL: https://leetcode.com/problems/number-of-boomerangs/
 */

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;

        int count = points.size();

        for (int i = 0; i < count; i++) {
            unordered_map<int, int> p;

            for (int j = 0; j < count; j++) {
                int dx = points[j].first - points[i].first;
                int dy = points[j].second - points[i].second;
                int d = dx * dx + dy * dy;
                if (p.find(d) != p.end()) {
                    res += p[d] * 2;
                    p[d]++;
                }
                else {
                    p[d] = 1;
                }
            }
        }
        return res;
    }
};
