#include <vector> 
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_set<int> s;
		for (auto i : nums1) {
			s.insert(i);
		}

		for (auto i : nums2) {
			if (s.find(i) != s.end()) {
				res.push_back(i);
				s.erase(i);
			}
		}
		return res;

	}
};