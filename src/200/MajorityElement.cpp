#include <vector> 

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, j = nums.size() - 1;
        int count = 0;

        while (res < j) {
            if (nums[res] != nums[j]) {
                if (count == 0) {
                    res++;
                }
                else {
                    count--;
                }
            }
            else {
                count++;
            }
            j--;
        }

        return nums[res];
    }
};