#include <vector> 
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (auto i : nums) {
            counts[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

        for (auto& pair : counts) {
            if (que.size() < k) {
                que.push(make_pair(pair.second, pair.first));
            }
            else {
                auto t = que.top();
                if (pair.second > t.first) {
                    que.pop();
                    que.push(make_pair(pair.second, pair.first));
                }
            }
        }
        vector<int> res;
        while (!que.empty()) {
            res.push_back(que.top().second);
            que.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};