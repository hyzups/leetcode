#include <vector> 
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0) - nums.size() * minNum;
    }
};