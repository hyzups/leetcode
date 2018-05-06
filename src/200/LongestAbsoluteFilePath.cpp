#include <vector>
#include <string> 
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthLongestPath(string input) {
		int ans = 0;

		int curr = 0;
		vector<int> paths;

		bool newLine = true, isFile = false;
		int level, start;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '\n') {
				newLine = true;
				level = 0;
				isFile = false;
			}
			else if (input[i] == '\t') {
				level++;
			}
			else {
				if (input[i] == '.') {
					isFile = true;
				}
				if (newLine) {
					while (level < paths.size()) {
						curr -= paths.back();
						paths.pop_back();
					}
					newLine = false;
					start = i;
				}
				if (input[i + 1] == '\n' || input[i + 1] == '\0') {
					int len = i - start + 1;
					curr += len;
					paths.push_back(len);
					if (isFile) {
						ans = max(ans, (int)(curr + paths.size() - 1));
					}

				}
			}
		}

		return ans;

	}
};