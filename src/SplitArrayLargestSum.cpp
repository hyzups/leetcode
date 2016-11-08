#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lb = nums[0];
        int ub = accumulate(nums.begin(), nums.end(), 0);


        while (ub - lb > 1) {
            int mid = lb + (ub - lb) / 2;
            if (canSplitArray(nums, m, mid)) {
                ub = mid;
            }
            else {
                lb = mid;
            }
        }
        return ub;
    }

    bool canSplitArray(vector<int> &nums, int m, int k) {
        int i = 0;
        while (i < nums.size()) {
            int sum = 0;
            while (sum + nums[i] <= k && i < nums.size()) {
                sum += nums[i];
                i++;
            }
            m--;
            if (m == 0) {
                break;
            }
        }
        return i == nums.size() && m >= 0;
    }
};