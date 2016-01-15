#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> res;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+"
                || tokens[i] == "-"
                || tokens[i] == "*"
                || tokens[i] == "/") {
                int num1 = res.top();
                res.pop();
                int num2 = res.top();
                res.pop();
                res.push(calc(num2, num1, tokens[i]));
            }
            else {
                res.push(stoi(tokens[i]));
            }
        }

        return res.top();
    }

    int calc(int a, int b, string token) {
        if (token == "*") {
            return a * b;
        }
        if (token == "/") {
            return a / b;
        }
        if (token == "+") {
            return a + b;
        }
        if (token == "-") {
            return a - b;
        }
        return -1;
    }
};