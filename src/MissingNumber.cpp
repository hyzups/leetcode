#include <vector>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int len = nums.size();
        int realSum = (len + 1)* len / 2;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        return realSum - sum;

    }
};