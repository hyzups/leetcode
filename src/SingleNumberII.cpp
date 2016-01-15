#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res = 0;
        int twos = 0, ones = 0;

        for (int i = 0; i < nums.size(); i++) {
            twos |= ones & nums[i];
            ones ^= nums[i];

            int commonBits = ones & twos;
            commonBits = ~commonBits;
            ones &= commonBits;
            twos &= commonBits;
        }
        return ones;
    }
};