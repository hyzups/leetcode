#include <string> 

using namespace std;

string itos[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f" };

class Solution {
public:
    string toHex(int num) {
        string res;
        unsigned int v = (unsigned)num;
        if (v == 0) {
            return "0";
        }

        while (v) {
            res = itos[v & 0xF] + res;
            v >>= 4;
        }
        return res;
    }
};