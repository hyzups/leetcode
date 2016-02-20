/// URL : https://leetcode.com/problems/find-the-duplicate-number/

#include <vector> 

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int temp = nums[i];
            while (temp != i + 1) {
                if (temp == nums[temp - 1]) {
                    return temp;
                }
                else {
                    swap(nums[i], nums[temp - 1]);
                    temp = nums[i];
                }
            }
        }
        return 0;
    }
};