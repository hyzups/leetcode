
#include <vector>
#include <algorithm>
#include <numeric>

using namespace  std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        vector<int> indices(len, 0);
        iota(indices.begin(), indices.end(), 0);

        mergeSort(nums, res, indices, 0, len - 1);
        return res;
    }

    void mergeSort(vector<int> &nums, vector<int> &res, vector<int> &indices, int l, int r) {
        if (l >= r) {
            return;
        }

        int mid = (l + r) / 2;

        mergeSort(nums, res, indices, l, mid);
        mergeSort(nums, res, indices, mid + 1, r);

        int index1 = l, index2 = mid + 1;

        vector<int> temp;
        int reverse = 0;
        while (index1 <= mid || index2 <= r) {
            if (index2 > r || (index1 <= mid  && nums[indices[index1]] <= nums[indices[index2]])) {
                temp.push_back(indices[index1]);
                res[indices[index1]] += reverse;
                index1++;
            }
            else {
                temp.push_back(indices[index2]);
                reverse++;
                index2++;
            }
        }
        move(temp.begin(), temp.end(), indices.begin() + l);
    }
};

