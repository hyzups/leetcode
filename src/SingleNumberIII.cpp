#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int com = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            com ^= nums[i];
        }

        int testBit = com & -com;

        int a = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & testBit) {
                a ^= nums[i];
            }
        }

        int b = com ^ a;
        return vector<int>{a, b};
    }
};