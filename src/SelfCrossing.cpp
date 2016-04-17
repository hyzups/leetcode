/// Source URL: https://leetcode.com/problems/self-crossing/

#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isSelfCrossing(vector<int>& nums) {

		int a[4] = { 0, 0, 0, 0 };

		int x = 0, y = 0;

		for (int i = 0; i < nums.size(); i++)
			if (i % 4 == 0) {
				x += nums[i];
				a[i % 4] = max(a[i % 4], x);
			}


	}
}; 