#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());

        int res = 0, index = 0;
        while (index < points.size()) {
            int currentRight = points[index].second;
            res++;

            while (++index < points.size() && points[index].first <= currentRight) {
                currentRight = min(currentRight, points[index].second);
            }
        }

        return res;
    }
};