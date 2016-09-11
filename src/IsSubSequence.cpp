#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int sLen = s.length();
		int tLen = t.length();

		if (sLen > tLen) {
			return false;
		}
		if (sLen == 0 && tLen == 0) {
			return true;
		}

		int sPos = 0, tPos = 0;

		while (tPos < tLen) {
			if (s[sPos] == t[tPos]) {
				++sPos;
			}

			if (sPos == sLen) {
				return true;
			}
			tPos++;
		}
		return false;
	}
};