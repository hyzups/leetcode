/// Source URL: https://leetcode.com/problems/wiggle-sort-ii/
/// 
/// Solution: Using 3-way partition as the dutch flag problem.


#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        auto nth = nums.begin() + n / 2;

        nth_element(nums.begin(), nth, nums.end());

        int median = *nth;
        int i = 0, j = 0, k = n - 1;

#define A(i) nums[(1 + 2 *i) %( n | 1)]

        while (j <= k) {
            if (A(j) == median) {
                j++;
            }
            else if (A(j) > median) {
                swap(A(i++), A(j++));
            }
            else {
                swap(A(j), A(k--));
            }
        }
    }
};