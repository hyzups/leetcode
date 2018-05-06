/// Source URL: https://leetcode.com/problems/summary-ranges/

#include <vector> 
#include <string> 

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string>  res;

        if (nums.size() > 0) {
            int start = nums[0];
            int end = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == end + 1) {
                    end = nums[i];
                    continue;
                }
                else {
                    addRange(res, start, end);
                    start = end = nums[i];
                }
            }
            addRange(res, start, end);
        }
        return res;
    }

    void addRange(vector<string> &res, int start, int end) {
        string s;
        s.append(to_string(start));
        if (start != end) {
            s.append("->");
            s.append(to_string(end));
        }
        res.push_back(s);
    }
};