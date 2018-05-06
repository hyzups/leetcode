#include <vector> 

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        long long  missing = 1, i = 0;
        while (missing <= n) {
            if (i < nums.size() && nums[i] <= missing) {
                missing += nums[i];
                i++;
            }
            else {
                missing += missing;
                res++;
            }
        }
        return res;
    }
};