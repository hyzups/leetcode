#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class NumArray {
public:

    NumArray(vector<int> &nums) {
        _sums.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            _sums.push_back(nums[i] + _sums.back());
        }
    }

    int sumRange(int i, int j) {
        return _sums[j + 1] - _sums[i];
    }
private:
    vector<int> _sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);