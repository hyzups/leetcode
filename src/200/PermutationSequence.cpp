/// Source URL: https://leetcode.com/problems/permutation-sequence/

#include<string>

using namespace std;

class Solution {

public:
    string getPermutation(int n, int k) {
        int total = 1;
        string nums, res;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i + '0');
            total *= i;
        }
        
        k--; 

        while (n > 0)
        {
            total /= n;
            int i = k / total;
            k = k % total;
            res.push_back(nums[i]);
            nums.erase(i);
            --n;
        }
        return res;
    }
};