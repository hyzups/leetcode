#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxOnBuy = INT_MIN;
        int maxOnSell = 0;
        int maxOnRest = 0;

        for (int i = 0; i < prices.size(); i++) {
            int prevBuy = maxOnBuy;
            maxOnBuy = max(maxOnRest - prices[i], maxOnBuy);
            maxOnRest = max(maxOnRest, maxOnSell);
            maxOnSell = max(prevBuy + prices[i], maxOnSell);
        }

        return maxOnSell;
    }
};
