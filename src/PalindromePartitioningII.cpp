#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.length();

        if (len < 2) {
            return 0;
        }

        vector<int> minCuts(len);
        vector<int> isP(len, false);

        minCuts[0] = 0;
        isP[0] = true;

        for (int i = 1; i < len; i++) {
            minCuts[i] = minCuts[i - 1] + 1;
            isP[i] = true;
            for (int j = 0; j < i; j++) {
                isP[j] = (s[i] == s[j]) && isP[j + 1];
                if (isP[j]) {
                    minCuts[i] = (j == 0) ? 0 : min(minCuts[i], minCuts[j - 1] + 1);
                }
            }
        }

        return minCuts[len - 1];
    }
};