#include<vector> 
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();

        vector<int> res(len, 1);

        int leftProd = 1, rightProd = 1;
        for (int i = 0; i < len; i++) {
            res[i] *= leftProd;
            res[len - 1 - i] *= rightProd;
            leftProd *= nums[i];
            rightProd *= nums[len - 1 - i];
        }
        return res;
    }
};