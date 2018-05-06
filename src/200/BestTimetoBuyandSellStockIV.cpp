#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();

        if (len < 2) {
            return 0;
        }
        else if (k >= len / 2) {
            return singleMaxProfile(prices);
        }


        vector<int> maxOnSell(k + 1, 0);
        vector<int> maxOnBuy(k + 1, INT_MIN);

        for (int i = 0; i < len; i++) {
            for (int j = k; j > 0; j--) {
                maxOnBuy[j] = max(maxOnBuy[j], maxOnSell[j - 1] - prices[i]);
                maxOnSell[j] = max(maxOnSell[j], maxOnBuy[j] + prices[i]);
            }
        }
        return maxOnSell[k];
    }

    int singleMaxProfile(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};