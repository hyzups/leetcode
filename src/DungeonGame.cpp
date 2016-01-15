#include <vector> 
#include <algorithm>

using namespace std; 
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int row = dungeon.size(); 
        if (row < 1) {
            return 0; 
        }
        int col = dungeon[0].size(); 
        if (col < 1) {
            return 0; 
        }

        vector<vector<int>> mins(row, vector<int>(col, 0)); 
        vector<vector<int>> remainings(row, vector<int>(col, 0));

        

    }
};