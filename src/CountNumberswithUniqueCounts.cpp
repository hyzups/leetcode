#include <numeric>
#include <vector>
#include <algorithm> 
#include <functional>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        vector<int> counts(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                counts[i] = 10;
            }
            else {
                counts[i] = (11 - i) * (i == 2 ? 9 : counts[i - 1]);
            }
        }

        return accumulate(counts.begin(), counts.end(), 0);
    }

};