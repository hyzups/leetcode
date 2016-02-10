// # URL:  https://leetcode.com/problems/two-sum/
// ## Two solutions for this question: 
// 
// ### Solution 1: Build the num and the index, then sort the array. Using pointers from both side walking towards the middle (meet at the middle) to find the solution. 
//                      Time complexity:  O(nlog(n)); Space complexity: O(1)
// 
// ### Solution 2: Using the unordered_map to save the visited elements.  When visited a number, first try to find the target complementary number. If find one, return the 
//                 result; otherwise, save the number to the map with number as the key and index as the value. 
//                      Time complexity:  O(n); Space complexity: O(n)

#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;

bool comparator(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); i++) {
            pairs.emplace_back(pair<int, int>(nums[i], i + 1));
        }
        sort(pairs.begin(), pairs.end(), comparator);

        int i = 0, j = nums.size() - 1;
        vector<int> result;
        while (i < j) {
            int sum = pairs[i].first + pairs[j].first;
            if (sum == target)
            {
                result.push_back(pairs[i].second);
                result.push_back(pairs[j].second);
                if (result[0] > result[1])
                {
                    swap(result[0], result[1]);
                }
                return result;
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return vector<int>();
    }
};