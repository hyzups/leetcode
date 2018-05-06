#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ans = 0;
        if (prices.size() < 1) {
            return ans;
        }

        int lowest = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - lowest);
            lowest = min(lowest, prices[i]);
        }
        return ans;
    }
};