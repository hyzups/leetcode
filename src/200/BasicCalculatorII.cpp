/// Source URL: https://leetcode.com/problems/basic-calculator-ii/

#include <string> 
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculate(string s) {

        int sign = 1;
        int res = 0;
        int num1 = 0;
        int num2 = 0;
        char op = '+';
        bool shouldCalc = false;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*' || s[i] == '/') {
                if (op != '+'&&  op != '-') {
                    num1 = (op == '*') ? num1 * num2 : num1 / num2;
                }
                op = s[i];
                num2 = 0;
                shouldCalc = true;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (shouldCalc) {
                    num1 = (op == '*') ? num1 * num2 : num1 / num2;
                    shouldCalc = false;
                }
                op = s[i];
                res += sign * num1;
                num1 = 0;
                sign = s[i] == '+' ? 1 : -1;
            }
            else if (isdigit(s[i])) {
                if (shouldCalc) {
                    num2 = num2 * 10 + s[i] - '0';
                }
                else {
                    num1 = num1 * 10 + s[i] - '0';
                }
            }
        }
        if (shouldCalc) {
            res += ((op == '*') ? num1 * num2 : num1 / num2) * sign;
        }
        else if (num1 != 0) {
            res += num1 * sign;
        }

        return res;
    }
};