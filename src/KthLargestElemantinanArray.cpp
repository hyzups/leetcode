#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int len = nums.size();
        if (k > len || len == 0) {
            return 0;
        }

        int left = 0, right = len - 1;
        while (left <= right) {
            int pivot = nums[left];
            int i = left + 1, j = right;
            while (i <= j)
            {
                while (nums[i] >= pivot && i <= j) i++;
                while (nums[j] < pivot) j--;
                if (i > j) break;
                swap(nums[i], nums[j]);
            }
            if (j == k - 1) {
                return pivot;
            }

            swap(nums[left], nums[j]);
            if (j > k - 1) {
                right = j - 1;
            }
            else {
                left = j + 1;
            }
        }
        return 0;
    }
};
