/// Source URL: https://leetcode.com/problems/palindrome-pairs/

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

struct TrieNode {
	int index;
	TrieNode* children[26];
	vector<int> l;

	TrieNode() {
		index = -1;
	}
};

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {

		vector<vector<int>> res;

		unordered_map<string, int> smap;
		for (size_t i = 0; i < words.size(); i++) {
			smap[words[i]] = i;
		}

		for (size_t i = 0; i < words.size(); i++) {
			for (size_t j = 0; j <= words[i].length(); j++) {
				string left = words[i].substr(0, j);
				string right = words[i].substr(j);
				string rleft = left;
				string rright = right;
				reverse(rleft.begin(), rleft.end());
				reverse(rright.begin(), rright.end());

				if (smap.find(rleft) != smap.end()) {
					if (smap[rleft] != i && isPalindrome(right)) {
						res.push_back(vector<int> {(int)i, smap[rleft]});
					}
				}

				if (j != 0 && smap.find(rright) != smap.end()) {
					if (smap[rright] != i && isPalindrome(left)) {
						res.push_back(vector<int>{ smap[rright], (int)i});
					}
				}
			}
		}


		return res;
	}


	bool isPalindrome(string& word) {
		if (word.length() < 2) {
			return true;
		}
		int i = 0, j = word.length() - 1;
		while (i < j) {
			if (word[i++] != word[j--]) {
				return false;
			}
		}
		return true;
	}
};