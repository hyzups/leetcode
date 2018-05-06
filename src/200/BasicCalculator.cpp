/// Source URL: https://leetcode.com/problems/basic-calculator/

#include <string> 
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {

        int res = 0;
        int num = 0;
        int sign = 1;

        stack<int> sta;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            else if (c == '+' || c == '-') {
                res += num * sign;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                sta.push(res);
                sta.push(sign);
                sign = 1;
                num = 0;
                res = 0;
            }
            else if (c == ')') {
                res += num * sign;
                num = 0;
                sign = 1;
                res *= sta.top();
                sta.pop();
                res += sta.top();
                sta.pop();
            }
        }

        if (num != 0) res += sign * num;

        return res;
    }

};