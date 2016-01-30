#include <vector> 
#include <algorithm>

using namespace std;


int dx[] = { 1, -1, 0, 0 };

int dy[] = { 0, 0, 1, -1 };

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> path(row, vector<int>(col, -1));

        int res = 1;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res = max(res, dfs(i, j, matrix, path, row, col));
            }
        }
        return res;
    }

    int dfs(int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &path, int row, int col) {
        if (path[m][n] > 0) {
            return path[m][n];
        }
        path[m][n] = 1;
        for (int i = 0; i < 4; i++) {
            int x = m + dx[i];
            int y = n + dy[i];
            if (x >= 0 && x < row && y >= 0 && y < col && matrix[x][y] > matrix[m][n]) {
                path[m][n] = max(path[m][n], 1 + dfs(x, y, matrix, path, row, col));
            }
        }
        return path[m][n];
    }
};