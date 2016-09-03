#include <cstdio>
#include <algorithm>
#include <vector> 

using namespace std;

class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		if (envelopes.size() < 2) {
			return envelopes.size();
		}
		sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
			return a.first <= b.first;
		});

		vector<int> dp(envelopes.size());

		auto compatible = [&envelopes](int a, int b) {
			return envelopes[a].first < envelopes[b].first && envelopes[a].second < envelopes[b].second;
		};

		dp[0] = 1;
		for (auto i = 1; i < envelopes.size(); ++i) {
			for (auto j = i - 1; j >= 0; --j) {
				if (compatible(j, i)) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}

		int res = dp[0];
		for (auto i = 0; i < envelopes.size(); i++) {
			res = max(res, dp[i]);
		}
		return res;
	}
};