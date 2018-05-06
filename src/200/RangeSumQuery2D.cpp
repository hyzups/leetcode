#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        m_sums = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                m_sums[i][j] = matrix[i - 1][j - 1] + m_sums[i - 1][j] + m_sums[i][j - 1] - m_sums[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return m_sums[row2 + 1][col2 + 1] - m_sums[row2 + 1][col1] - m_sums[row1][col2 + 1] + m_sums[row1][col1];

    }

private:
    vector<vector<int>> m_sums;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);s