/// Source URL: https://leetcode.com/problems/remove-k-digits/

#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;

        for (char c : num) {
            while (res.length() && c < res.back() && k > 0) {
                k--;
                res.pop_back();
            }
            if (res.length() || c != '0') {
                res.push_back(c);
            }
        }

        while (!res.empty() && k > 0) {
            res.pop_back();
            k--;
        }

        return res.empty() ? "0" : res;
    }
};

