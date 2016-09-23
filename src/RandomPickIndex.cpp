#include <vector>
#include <cmath> 

using namespace std;

class Solution {
private:
    vector<int> m_nums;
public:
    Solution(vector<int> nums) : m_nums(nums) {

    }

    int pick(int target) {
        int result = -1;
        int count = 0;
        for (int i = 0; i < m_nums.size(); i++) {
            if (m_nums[i] != target) {
                continue;
            }
            count++;
            int r = rand() % count;
            if (r == 0) {
                result = i;
            }
        }

        return result;
    }
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* int param_1 = obj.pick(target);
*/