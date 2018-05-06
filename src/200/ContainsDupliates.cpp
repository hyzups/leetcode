/// Source URL: https://leetcode.com/problems/contains-duplicate/

#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return    nums.end() - unique(nums.begin(), nums.end()) != 0;
    }
};