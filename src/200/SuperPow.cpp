#include <vector> 

using namespace std;

class Solution {
	const int BASE = 1337;

	int powmod(int a, int k) {
		int res = 1;
		a %= BASE;
		for (int i = 0; i < k; i++) {
			res = (res * a) % BASE;
		}
		return res;
	}

public:
	int superPow(int a, vector<int>& b) {
		if (b.empty()) {
			return 1;
		}

		int lastDigit = b.back();
		b.pop_back();

		return (powmod(superPow(a, b), 10) * powmod(a, lastDigit)) % BASE;

	}
};