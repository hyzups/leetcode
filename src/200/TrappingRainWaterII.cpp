#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

const int dx[] = { 1, -1 , 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int res = 0;

        int row = heightMap.size();
        if (row < 3) {
            return res;
        }
        int col = heightMap[0].size();
        if (col < 3) {
            return res;
        }

        using Item = pair<int, pair<int, int>>;

        auto comp = [](const Item  &a, const Item &b) {
            return a.first > b.first;
        };

        priority_queue<Item, vector<Item>, decltype(comp)> q(comp);

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < col; i++) {
            q.emplace(make_pair(heightMap[0][i], make_pair(0, i)));
            q.emplace(make_pair(heightMap[row - 1][i], make_pair(row - 1, i)));
            visited[0][i] = visited[row - 1][i] = true;
        }

        for (int i = 1; i < row - 1; i++) {
            q.emplace(make_pair(heightMap[i][0], make_pair(i, 0)));
            q.emplace(make_pair(heightMap[i][col - 1], make_pair(i, col - 1)));
            visited[i][0] = visited[i][col - 1] = true;
        }

        while (!q.empty()) {
            auto temp = q.top();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = temp.second.first + dx[i];
                int y = temp.second.second + dy[i];
                if (x >= 0 && x < row && y >= 0 && y < col && !visited[x][y]) {
                    if (heightMap[x][y] < temp.first) {
                        res += temp.first - heightMap[x][y];
                        heightMap[x][y] = temp.first;
                    }
                    q.emplace(make_pair(heightMap[x][y], make_pair(x, y)));
                    visited[x][y] = true;
                }
            }
        }
        return res;
    }
};