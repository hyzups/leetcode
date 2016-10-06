/// Source URL: https://leetcode.com/problems/shortest-palindrome/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string revS = s;
        reverse(revS.begin(), revS.end());

        string temp = s + "#" + revS;

        vector<int>  kmp(temp.size(), 0);
        int i = 1, j = 0;
        while (i < temp.size()) {
            if (temp[i] == temp[j]) {
                kmp[i] = ++j;
                i++;
            }
            else {
                if (j == 0) {
                    kmp[i] = 0;
                    i++;
                }
                else {
                    j = kmp[j - 1];
                }
            }
        }

        return revS.substr(0, s.size() - kmp[temp.size() - 1]) + s;
    }
};
