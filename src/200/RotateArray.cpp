/// Source URL: https://leetcode.com/problems/rotate-array/
/// There are more than three solutions, see https://leetcode.com/discuss/27387/summary-of-c-solutions 
/// for more detailed solutions. 

#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) {
            return;
        }

        for (int i = 0; i < gcd(n, k); i++) {
            int temp = nums[i];
            int j = (i + k) % n;
            while (i != j) {
                int temp2 = nums[j];
                nums[j] = temp;
                temp = temp2;
                j = (j + k) % n;
            }
            nums[i] = temp;
        }
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
