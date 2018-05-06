#include <vector> 
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        auto  s = nums.size();

        if (s < 2) {
            return 1;
        }
        vector<int> highSequence(s, 1);
        vector<int> lowSequence(s, 1);

        for (int i = 1; i < s; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    highSequence[i] = max(highSequence[i], lowSequence[j] + 1);
                }
                else if (nums[i] < nums[j]) {
                    lowSequence[i] = max(lowSequence[i], highSequence[j] + 1);
                }
            }
        }

        int res = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            res = max(res, highSequence[i]);
            res = max(res, lowSequence[i]);
        }
        return res;
    }
};

//int main() {
//    Solution s;
//    s.wiggleMaxLength(vector<int>{1, 7});
//}