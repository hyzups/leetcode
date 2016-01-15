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