/// Source URL: https://leetcode.com/problems/happy-number/

#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace  std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        visited.insert(n);

        while (true) {
            if (n == 1) {
                break;
            }
            n = sum(n);
            if (visited.find(n) != visited.end()) {
                return false;
            }
            visited.insert(n);
        }
        return true;
    }

    int sum(int n) {
        int res = 0;
        while (n != 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};