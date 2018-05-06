#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> bitMasks(len, 0);

        for (int i = 0; i < len; i++) {
            int mask = 0;
            for (char c : words[i]) {
                mask |= (1 << (c - 'a'));
            }
            bitMasks[i] = mask;
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (!(bitMasks[i] & bitMasks[j])) {
                    res = max(res, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return res;
    }
};