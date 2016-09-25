
class Solution {
public:
    int integerReplacement(int n) {

        int res = 0;
        while (n > 1) {
            if (n & 1) {
                if (n == 3) {
                    return res + 2;
                }
                else if ((n & 3) == 3) {
                    n++;
                }
                else {
                    n--;
                }
            }
            else {
                n = n >> 1;
            }
            res++;
        }
        return res;
    }
};