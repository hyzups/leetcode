#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

		if (nums1.empty() || nums2.empty()) {
			return vector<pair<int, int>>();
		}


		auto comp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
			return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
		};

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> que(comp);

		for (int i = 0; i < nums2.size(); i++) {
			que.push(make_pair(0, i));
		}

		vector<pair<int, int>> res;

		int count = 0;
		while (count < k && !que.empty()) {
			auto tmp = que.top();
			que.pop();
			res.push_back(make_pair(nums1[tmp.first], nums2[tmp.second]));

			if (tmp.first < nums1.size() - 1) {
				que.push(make_pair(tmp.first + 1, tmp.second));
			}
			++count;
		}
		return res;
	}
};