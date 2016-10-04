#include <vector> 
#include <algorithm>

using namespace std;

static int dx[] = { -1, 0, 1 };
static int dy[] = { -1, 0, 1 };

const int lowMask = 0xFFFF;
const int highMask = 0xFFFF0000;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int cnt = 0;
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        int x = i + dx[m];
                        int y = j + dy[n];

                        if (x >= 0 && x < row && y >= 0 && y < col && !(x == i && y == j)) {
                            cnt += board[x][y] & lowMask;
                        }
                    }
                }

                board[i][j] |= cnt << 16;
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int cnt = (board[i][j] & highMask) >> 16;
                int state = board[i][j] & lowMask;
                if (state == 1) {
                    if (cnt > 3 || cnt < 2) {
                        board[i][j] = 0;
                    }
                    else {
                        board[i][j] = 1;
                    }
                }
                else {
                    if (cnt == 3) {
                        board[i][j] = 1;
                    }
                    else {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};