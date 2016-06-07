#include <vector> 
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> res;

		for (int i = 0; i <= k; i++) {
			vector<int> res1 = getMaximuNumber(nums1, i);
			vector<int> res2 = getMaximuNumber(nums2, k - i);
			vector<int> tempRes = getMaximumNumber(res1, res2);
			if (compareArray(tempRes, res)) {
				res = tempRes;
			}
		}

		return res;
	}

	bool compareArray(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() != nums2.size()) {
			return nums1.size() > nums2.size();
		}

		int i = 0;
		while (i < nums1.size() && i < nums2.size()) {
			if (nums1[i] == nums2[i]) {
				i++;
			}
			else {
				return nums1[i] > nums2[i];
			}
		}
		return true;
	}

	vector<int> getMaximumNumber(vector<int>& nums1, vector<int>& nums2) {
		vector<int> out;
		while (nums1.size() + nums2.size()) {
			vector<int>& now = nums1 > nums2 ? nums1 : nums2;
			out.push_back(now[0]);
			now.erase(now.begin());
		}
		return out;
	}

	vector<int> getMaximuNumber(vector<int> &nums, int len) {
		vector<int> res;

		if (len == 0) {
			return res;
		}

		if (len >= nums.size()) {
			res = nums;
			return res;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (res.empty() && len > 0) {
				res.push_back(nums[i]);
			}
			else if (nums[i] > res.back()) {
				while (!res.empty() && nums[i] > res.back() && nums.size() - i > len - res.size()) {
					res.pop_back();
				}
				res.push_back(nums[i]);
			}
			else if (res.size() < len) {
				res.push_back(nums[i]);
			}
		}
		return res;
	}
};

int main() {
	vector<int> v1{ 1, 2 };
	vector<int> v2{};

	Solution s;
	s.maxNumber(v1, v2, 2);
}