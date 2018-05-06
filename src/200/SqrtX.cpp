#include <cmath>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        long long l = 0, r = x / 2 + 1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long  s = mid * mid;
            if (s == x) {
                return mid;
            }
            else if (s > x) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
};
