/// Source URL: https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>> mem;
		return computeRecursively(input, mem);
	}

	vector<int> computeRecursively(string input, unordered_map<string, vector<int>>& mem) {
		vector<int> res;
		for (int i = 0; i < input.length(); i++) {
			char cur = input[i];
			if (cur == '+' || cur == '-' || cur == '*') {
				vector<int> resLeft;
				vector<int> resRirght;
				string substr = input.substr(0, i);
				if (mem.find(substr) != mem.end()) {
					resLeft = mem[substr];
				}
				else {
					resLeft = computeRecursively(substr, mem);
				}
				substr = input.substr(i + 1);
				if (mem.find(substr) != mem.end()) {
					resRirght = mem[substr];
				}
				else {
					resRirght = computeRecursively(substr, mem);
				}

				for (auto& n1 : resLeft) {
					for (auto& n2 : resRirght) {
						if (cur == '+') {
							res.push_back(n1 + n2);
						}
						else if (cur == '-') {
							res.push_back(n1 - n2);
						}
						else {
							res.push_back(n1 * n2);
						}
					}
				}
			}
		}

		if (res.empty()) {
			res.push_back(stoi(input));
		}

		return res;
	}
};