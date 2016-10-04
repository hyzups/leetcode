#include <vector> 
#include <string> 

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return false;
        }
        int x = 0, y = col - 1;

        while (x < row && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            else if (matrix[x][y] < target) {
                x++;
            }
            else {
                y--;
            }
        }
        return false;
    }
};