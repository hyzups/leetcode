#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int pos = 0;
		return decodeStringRecursively(s, pos);
	}

	string decodeStringRecursively(string &s, int& pos) {
		string res;
		while (pos < s.length() && s[pos] != ']') {
			if (isdigit(s[pos])) {
				int count = 0;
				while (s[pos] != '[') {
					count = count * 10 + s[pos] - '0';
					++pos;
				}
				string subString = decodeStringRecursively(s, ++pos);
				for (int i = 0; i < count; i++) {
					res.append(subString);
				}
			}
			else {
				int start = pos;
				while (s[pos] != ']' && !isdigit(s[pos])) ++pos;
				string subString = s.substr(start, pos - start);
				res.append(subString);
				if (s[pos] == ']') {
					pos++;
					return res;
				}
			}
		}
		if (s[pos] == ']') {
			++pos;
		}
		return res;
	}
};