#include <vector> 

using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> sums(target + 1, 0);

		for (int i = 1; i <= target; i++) {
			for (int num : nums) {
				if (num == i) {
					sums[i] += 1;
				}
				else if (num < i) {
					sums[i] += sums[i - num];
				}
			}
		}
		return sums[target];
	}
};