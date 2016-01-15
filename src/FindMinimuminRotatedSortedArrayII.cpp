#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r && nums[l] >= nums[r]) {
            int mid = (l + r) / 2;
            if (nums[l] < nums[mid]) {
                l = mid + 1;
            }
            else if (nums[mid] < nums[r]) {
                r = mid;
            }
            else {
                l++;
            }
        }
        return nums[l];
    }
};