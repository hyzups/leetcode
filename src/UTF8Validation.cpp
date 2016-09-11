#include <vector> 
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {

        int i = 0;
        while (i < data.size()) {
            if (data[i] >> 7 ^ 1) {
                i++;
            }
            else if (data[i] >> 5 == 0x6) {
                if (i + 1 < data.size() && (data[i + 1] >> 6) == 0x2) {
                    i += 2;
                }
                else {
                    return false;
                }
            }
            else if (data[i] >> 4 == 0xE) {
                if (i + 2 < data.size() && (data[i + 1] >> 6) == 0x2 && (data[i + 2] >> 6) == 0x2) {
                    i += 3;
                }
                else {
                    return false;
                }
            }
            else if (data[i] >> 3 == 0x1E) {
                if (i + 3 < data.size() && (data[i + 1] >> 6) == 0x2 && (data[i + 2] >> 6) == 0x2 && (data[i + 1] >> 6) == 0x2) {
                    i += 4;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }

        }
        return true;
    }
};