#include <vector>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {

        if (num.length() < 3) {
            return false;
        }

        for (int i = 0; i < num.length() - 2; i++) {

            if (i > 0 && num[0] == '0') {
                return false;
            }

            for (int j = i + 1; j < num.length() - 1; j++) {

                if (j > i + 1 && num[i + 1] == '0') {
                    break;
                }

                long long first = atol(num.substr(0, i + 1).c_str());
                long long second = atol(num.substr(i + 1, j - i).c_str());
                if (isAdditiveNumber(num, first, second, j + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isAdditiveNumber(string &num, long long first, long long second, int pos) {
        if (num.length() == pos) {
            return true;
        }
        for (int i = pos; i < num.length(); i++) {
            if (i > pos && num[i] == '0') {
                return false;
            }
            long long current = atol(num.substr(pos, i - pos + 1).c_str());
            if (first + second == current) {
                return isAdditiveNumber(num, second, current, i + 1);
            }
            else if (first + second < current) {
                return false;
            }
        }
        return false;
    }
};