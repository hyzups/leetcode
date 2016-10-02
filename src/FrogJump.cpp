#include <vector>
#include <set>
#include <algorithm> 
#include <functional>
#include <unordered_map>

using namespace std;

static int dx[] = { -1, 0, 1 };

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        unordered_map<int, vector<int>> steps;

        for (auto i : stones) {
            steps[i] = vector<int>();
        }

        steps[0].push_back(0);

        for (auto i : stones) {
            for (auto j : steps[i])
                for (int k = 0; k <= 2; k++) {
                    int nextStep = j + dx[k];
                    if (nextStep) {
                        if (steps.find(nextStep + i) != steps.end()) {
                            steps[i + nextStep].push_back(nextStep);
                        }
                    }
                }
        }

        if (steps[stones[len - 1]].size() > 0) {
            return true;
        }
        return false;
    }
};