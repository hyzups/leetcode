#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX / 2;

        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            int j = i + 1, k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
                if (sum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return res;
    }
};