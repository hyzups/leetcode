/// Source URL: https://leetcode.com/problems/integer-break/
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		if (n == 2) {
			return 1;
		}
		else if (n == 3) {
			return 2;
		}
		else if (n % 3 == 0) {
			return pow(3, n / 3);
		}
		else if (n % 3 == 2) {
			return 2 * pow(3, (n - 2) / 3);
		}
		else {
			return  4 * pow(3, (n - 4) / 3);
		}
	}
};