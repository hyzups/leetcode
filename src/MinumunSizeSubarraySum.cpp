#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int res = INT_MAX;

        int sum = 0, start = 0, end = 0, len = nums.size();
        while (true) {
            while (end < len && sum < s) {
                sum += nums[end++];
            }

            if (sum < s) {
                break;
            }

            res = min(res, end - start);

            sum -= nums[start++];
        }

        return res == INT_MAX ? 0 : res;
    }
};