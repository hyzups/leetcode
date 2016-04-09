/// Source URL: https://leetcode.com/problems/increasing-triplet-subsequence/

#include<vector> 

using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		if (len < 3) {
			return false;
		}

		int c1 = INT_MAX, c2 = INT_MAX;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= c1) {
				c1 = nums[i];
			}
			else if (nums[i] <= c2) {
				c2 = nums[i];
			}
			else {
				return true;
			}
		}
		return false;
	}
};