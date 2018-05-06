/// Source URL: https://leetcode.com/problems/number-of-digit-one/

#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		int res = 0;
		int factor = 1;
		while (factor <= n) {
			if ((n / factor) % 10 == 1) {
				res += (n / (10 * factor)) * factor + n % factor + 1;
			}
			else {
				res += (n / (10 * factor) + 1) * factor;
			}
			factor *= 10;
		}
		return res;
	}
};