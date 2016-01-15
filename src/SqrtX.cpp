#include <cmath>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        long long l = 0, r = x;
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long  s = mid * mid;
            if (s == x) {
                return mid;
            }
            else if (s < r) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};