#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstdio>

class Solution {
public:
    int nthUglyNumber(int n)
    {
        int i = 0, j = 0, k = 0;

        std::vector<int> res;
        res.push_back(1);
        int index = n;
        while (--index > 0)
        {
            int tmp = std::min(res[i] * 2, std::min(res[j] * 3, res[k] * 5));
            if (tmp == res[i] * 2) i++;
            if (tmp == res[j] * 3) j++;
            if (tmp == res[k] * 5) k++;
            res.push_back(tmp);
        }
        return res[n - 1];
    }
};