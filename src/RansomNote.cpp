#include <vector> 

using namespace std;
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {

		vector<int> nums(256, 0);
		for (auto c : magazine) {
			nums[c]++;
		}
		for (auto c : ransomNote) {
			if (--nums[c] < 0) {
				return false;
			}
		}
		return true;
	}
};