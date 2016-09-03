#include <string>
#include <vector> 
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		vector<int> diff(26, 0);
		for (auto c : s) {
			diff[c - 'a']++;
		}

		for (auto c : t) {
			diff[c - 'a']--;
		}

		char res;
		for (int i = 0; i < 26; i++) {
			if (diff[i] > 0) {
				res = 'a' + i;
			}
		}
		return res;
	}
};