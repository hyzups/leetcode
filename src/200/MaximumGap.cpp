#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return 0;
        }
        else if (len == 2) {
            return abs(nums[1] - nums[0]);
        }


        int iMin = nums[0], iMax = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i] < iMin) {
                iMin = nums[i];
            }
            else if (nums[i] > iMax) {
                iMax = nums[i];
            }
        }
        int bucketSize = max(1, (iMax - iMin) / (len - 1));
        int bucketNum = (iMax - iMin) / bucketSize + 1;

        vector<pair<int, int>> bucket(bucketNum, pair<int, int>(-1, -1));


        for (int i = 0; i < len; i++) {
            int index = (nums[i] - iMin) / bucketSize;
            if (bucket[index].first == -1 || bucket[index].first > nums[i]) {
                bucket[index].first = nums[i];
            }
            if (bucket[index].second == -1 || bucket[index].second < nums[i]) {
                bucket[index].second = nums[i];
            }
        }

        int res = 0, pre = 0;

        for (int i = 1; i < bucketNum; i++) {
            if (bucket[i].first == -1) {
                continue;
            }
            else {
                res = max(res, bucket[i].first - bucket[pre].second);
                pre = i;
            }
        }

        return res;
    }
};
