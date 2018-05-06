/// Source URL: https://leetcode.com/problems/number-of-islands/

#include <vector>

using namespace std;

class Solution {

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) {
            return  0;
        }
        int col = grid[0].size();
        if (col == 0) {
            return 0;
        }

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    dfs(grid, row, col, i, j, visited);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> &grid, int row, int col, int x, int y, vector<vector<bool>> &visited) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i], newY = y + dy[i];
            if (newX >= 0 && newX < row  && newY >= 0 && newY < col && !visited[newX][newY] && grid[newX][newY] == '1') {
                dfs(grid, row, col, newX, newY, visited);
            }
        }
    }
};