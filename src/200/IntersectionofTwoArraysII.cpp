#include <vector> 
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map<int, int> m; 
		for (auto n : nums1) {
			m[n]++;
		}

		for (auto n : nums2) {
			if (m.find(n) != m.end() && m[n] > 0) {
				res.push_back(n);
				m[n]--;
			}
		}

		return res; 
	}
};