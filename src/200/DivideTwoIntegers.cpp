#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (divisor == 1)
            return dividend;
        if (dividend == INT_MIN && abs(divisor) == 1)
            return INT_MAX;

        bool negative = dividend > 0 ^ divisor > 0;

        long long remaining = llabs(dividend);
        long long visor = llabs(divisor);

        long long res = 0;

        while (remaining >= visor) {
            long long temp = visor;
            long long div = 1;
            while (remaining >= temp) {
                remaining -= temp;
                res += div;
                div <<= 1;
                temp <<= 1;
            }
        }

        return ((dividend ^ divisor) >> 31) ? -res : res;
    }
};