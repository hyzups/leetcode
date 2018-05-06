#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int i = 0; i < nums.size(); i++) {
            numSet.insert(nums[i]);
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (numSet.find(nums[i]) != numSet.end()) {
                int tempRes = 1;
                numSet.erase(nums[i]);
                int value = nums[i] + 1;
                while (numSet.find(value) != numSet.end()) {
                    tempRes++;
                    numSet.erase(value);
                    value++;
                }
                value = nums[i] - 1;
                while (numSet.find(value) != numSet.end()) {
                    tempRes++;
                    numSet.erase(value);
                    value--;
                }

                res = max(res, tempRes);
            }
        }

        return res;
    }
};