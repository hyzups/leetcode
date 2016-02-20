#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }

        int f1 = nums[1], f2 = 0;
        for (int i = 2; i < n - 1; i++) {
            int temp = max(f2, f1 + nums[i]);
            f1 = f2;
            f2 = temp;
        }

        int res = max(f1, f2);

        f1 = 0; f2 = nums[1];
        for (int i = 2; i < n; i++) {
            int temp = max(f2, f1 + nums[i]);
            f1 = f2;
            f2 = temp;
        }
        return max(res, f2);
    }
};