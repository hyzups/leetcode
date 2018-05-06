#include <vector> 

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1; 

        int current = 1; 
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i < colEnd; i++) {
                res[rowBegin][i] = current++;
            }
            rowBegin++; 
            if (rowBegin <= rowEnd) {
                for (int i = rowBegin; i <= rowEnd; i++) {
                    res[i][colEnd] = current++;
                }
            }
            colEnd--;
            if (colBegin <= colEnd) {
                for (int i = colEnd; i >= colBegin; i--) {
                    res[rowEnd][i] = current++;
                }
            }
            rowEnd--;

            if (rowBegin <= rowEnd) {
                for (int i = rowEnd; i >= rowBegin; i--) {
                    res[i][colBegin] = current++;
                }
            }
            colBegin++;
        }
        return res;
    }
};