#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		int l = s.length();
		for (int i = 0; i < l / 2; i++) {
			swap(s[i], s[l - 1 - i]);
		}
		return s;

	}
};