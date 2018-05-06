/// Source URL:  https://leetcode.com/problems/rectangle-area/

#include <algorithm>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E);
        int right = min(C, G);
        int top = min(D, H);
        int bottom = max(B, F);
        int overlap = 0;
        if (left < right &&  top <= bottom) {
            overlap = (right - left) * (top - bottom);
        }

        return  (C - A) * (D - B) + (G - E) * (H - F) - overlap;
    }
};