#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {

        long long  ans = 0;


        bool start = false;
        int sign = 1;

        int index = 0;

        while (index < str.length() && str[index] == ' ') index++;

        if (str[index] == '+' || str[index] == '-') {
            if (str[index] == '-') {
                sign = -1;
            }
            index++;
        }

        while (index < str.length() && isdigit(str[index])) {
            ans = ans * 10 + str[index] - '0';
            if (ans > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }

        ans = ans * sign;

        if (ans <= INT_MIN) {
            return INT_MIN;
        }

        return ans;
    }
};



