#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0; i < 16; i++) {
            n = swap(n, i, 31 - i);
        }
        return n;
    }

    uint32_t swap(uint32_t n, int i, int j) {
        if (((n >> i) & 1 ^ (n >> j) & 1)) {
            n = n ^ (1 << i);
            n = n ^ (1 << j);
        }
        return n;
    }
};