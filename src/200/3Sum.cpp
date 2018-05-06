#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int len = nums.size();

        for (int i = 0; i < len - 2; i++) {
            if (i  && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1, k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.emplace_back(temp);
                    do { j++; } while (nums[j] == nums[j - 1] && j < k);
                    do { k--; } while (nums[k] == nums[k + 1] && j < k);
                }
                else if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
            }
        }
        return ans;
    }
};