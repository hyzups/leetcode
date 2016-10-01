#include <vector>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        if (matrix.empty()) {
            return 0;
        }

        int ans = INT_MIN;

        int row = matrix.size();
        int col = matrix[0].size();

        for (int l = 0; l < col; l++) {
            vector<int> sums(row, 0);
            for (int r = l; r < col; r++) {
                for (int i = 0; i < row; i++) {
                    sums[i] += matrix[i][r];
                }

                int currMax = INT_MIN;
                int currSum = 0;

                set<int> accuSet;
                accuSet.insert(0);

                for (int sum : sums) {
                    currSum += sum;
                    auto iter = accuSet.lower_bound(currSum - k);
                    if (iter != accuSet.end()) {
                        currMax = std::max(currMax, currSum - *iter);
                    }
                    accuSet.insert(currSum);
                }

                ans = max(ans, currMax);
            }
        }

        return ans;
    }
};