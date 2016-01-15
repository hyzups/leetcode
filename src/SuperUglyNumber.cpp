#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        int len = primes.size();
        vector<int> res;
        vector<int> index(len, 0);

        res.push_back(1);
        int i = 1;
        while (i < n) {
            int minValue = INT_MAX;
            for (int j = 0; j < len; j++) {
                if (primes[j] * res[index[j]] < minValue) {
                    minValue = primes[j] * res[index[j]];
                }
            }
            res.push_back(minValue);

            for (int j = 0; j < len; j++) {
                if (minValue % primes[j] == 0) {
                    index[j]++;
                }
            }
            i++;
        }
        return res[n - 1];
    }
};