#include <vector> 
#include <algorithm>

using namespace std;

class Solution {

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();

        vector<long long>  sums(len + 1, 0);
        for (int i = 0; i < len; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }

        return countWhileMergeSort(sums, 0, len + 1, lower, upper);
    }

    int countWhileMergeSort(vector<long long> &sums, int left, int right, int lower, int upper) {
        int res = 0;
        int mid = (left + right) / 2;

        if (right - left <= 1) {
            return 0;
        }

        res += countWhileMergeSort(sums, left, mid, lower, upper);
        res += countWhileMergeSort(sums, mid, right, lower, upper);

        vector<long long> cache(right - left, 0);

        int m = mid, n = mid, j = mid;
        int r = 0;
        for (int i = left; i < mid; i++) {
            while (m < right && sums[m] < sums[i] + lower) m++;
            while (n < right && sums[n] <= sums[i] + upper) n++;

            while (j < right && sums[i] > sums[j]) cache[r++] = sums[j++];
            cache[r++] = sums[i];
            res += n - m;
        }
        move(cache.begin(), cache.begin() + r, sums.begin() + left);

        return res;
    }
};
