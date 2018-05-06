#include <vector> 
using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            int mid1 = mid + 1;
            if (nums[mid] <= nums[mid1]) {
                l = mid1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};