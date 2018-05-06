#include <vector> 
#include <algorithm>

using namespace std;

static int dx[4]{ 1, -1, 0, 0 };
static int dy[4]{ 0, 0, 1, -1 };

class Solution {

private:

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if (row == 0) {
            return false;
        }
        int col = board[0].size();
        if (col == 0) {
            return false;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                vector<vector<bool>> visited(row, vector<bool>(col, false));
                if (findWord(i, j, board, visited, 0, word)) {
                    return true;
                }

            }
        }
        return false;
    }


    bool findWord(int m, int n, vector<vector<char>> &board, vector<vector<bool>> &visited, int curpos, string& word) {
        if (word[curpos] == board[m][n]) {
            if (curpos == word.length() - 1) {
                return true;
            }
            visited[m][n] = true;

            for (int i = 0; i < 4; i++) {
                int x = m + dx[i];
                int y = n + dy[i];
                if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !visited[x][y]) {
                    if (findWord(x, y, board, visited, curpos + 1, word)) {
                        return true;
                    }
                }
            }
            visited[m][n] = false;
        }
        return false;
    }
};