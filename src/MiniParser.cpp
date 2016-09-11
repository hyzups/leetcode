#include <vector>
#include <cctype>
#include <numeric>

using namespace std;

// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Constructor initializes an empty nested list.
	NestedInteger();

	// Constructor initializes a single integer.
	NestedInteger(int value);

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Set this NestedInteger to hold a single integer.
	void setInteger(int value);

	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger &ni);

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

class Solution {
public:
	NestedInteger deserialize(string s) {
		int pos = 0; 
		return deserializeRecursively(s, pos);
	}

	NestedInteger deserializeRecursively(string &s, int& pos) {
		if (s[pos] == '[') {
			NestedInteger n;
			pos++;
			while (s[pos] != ']') {
				n.add(deserializeRecursively(s, pos));
			}
			pos++;
			return n;
		}
		else if (isdigit(s[pos]) || s[pos] == '-') {
			int res = 1;
			int sign = 1;
			if (s[pos] == '-') {
				pos++;
				sign = -1;
			}
			while (s[pos] != ',' && s[pos] != '\0') {
				res = res * 10 + s[pos] - '0';
				pos++;
			}
			NestedInteger n;
			n.setInteger(res * sign);
			pos++;
			return n;
		}
	}
};