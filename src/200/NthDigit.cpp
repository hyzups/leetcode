#include <numeric>
#include <cmath>

using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        int low = 1, high = INT_MAX;

        int len = 1;
        int start = 1;
        long count = 9;

        while (n > len * count)
        {
            n -= len * count;
            ++len;
            count *= 10;
            start *= 10;
        }

        start = start + (n - 1) / len;
        n = (n - 1) % len;

        return (start / (int)pow(10, len - n - 1)) % 10;
    }
};