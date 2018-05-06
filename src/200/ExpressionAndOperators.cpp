/// Source URL: https://leetcode.com/problems/expression-add-operators/

#include <string> 
#include <vector> 

using namespace std;

class Solution {
public:
	vector<string> addOperators(string num, int target) {

		vector<string> res;
		if (num.length() < 1) {
			return res;
		}

		string curr = "";
		dfs(res, curr, num, target, 0, 0, 0);
		return res;
	}

	void dfs(vector<string> &res, string curr, string &num, int target, int pos, long long calculated, long long  prevNum) {
		if (pos == num.length() && calculated == target) {
			res.push_back(curr);
			return;
		}

		for (int i = pos + 1; i <= num.length(); i++) {
			string tmp = num.substr(pos, i - pos);
			long long currNum = stoll(tmp);
			if (i != pos + 1 && num[pos] == '0') {
				break;
			}
			if (pos == 0) {
				dfs(res, curr + tmp, num, target, i, currNum, currNum);
			}
			else {
				dfs(res, curr + "+" + tmp, num, target, i, calculated + currNum, currNum);
				dfs(res, curr + "-" + tmp, num, target, i, calculated - currNum, -currNum);
				dfs(res, curr + "*" + tmp, num, target, i, calculated - prevNum + prevNum * currNum, prevNum * currNum);
			}
		}

	}
};