#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                int time = (i << 6) + j;
                if (countBits(time) == num) {
                    res.push_back(to_string(i) + ":" + (j > 9 ? "" : "0") + to_string(j));
                }
            }
        }
        return res;
    }

    int countBits(int num) {
        int res = 0;
        while (num) {
            res++;
            num = num & (num - 1);
        }
        return res;
    }
};