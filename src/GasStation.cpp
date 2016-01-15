#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s = gas.size();

        int totalSum = 0, currentSum = 0, start = 0;

        for (int i = 0; i < s; i++) {
            totalSum += gas[i] - cost[i];
            currentSum += gas[i] - cost[i];
            if (currentSum < 0) {
                start = i + 1;
                currentSum = 0;
            }
        }

        if (totalSum >= 0) {
            return start;
        }
        return -1;
    }
};