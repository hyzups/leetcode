/// Source URL: https://leetcode.com/problems/count-primes/

#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return n;
        }

        vector<bool> isPrime(n + 1, true);
        int res = 1;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                res++;
                for (int k = i; k * k <= n; k++) {
                    isPrime[i * k] = false;
                }
            }
        }
        return res;
    }
};