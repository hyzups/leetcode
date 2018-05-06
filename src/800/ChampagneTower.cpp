#include <algorithm>
#include <vector> 

using namespace std;

const int MAX_ROW = 101;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>> glasses(MAX_ROW, vector<double>(MAX_ROW, 0.0));
        glasses[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (glasses[i][j] > 1) {

                    glasses[i + 1][j] += (glasses[i][j] - 1) / 2;
                    glasses[i + 1][j + 1] += (glasses[i][j] - 1) / 2;
                    glasses[i][j] = 1;
                }
            }
        }
        return glasses[query_row][query_glass];
    }
};