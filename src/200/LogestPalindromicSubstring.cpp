#include <vector>
#include <string> 
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }

        string res = s.substr(0, 1);
        int maxLen = 1;

        for (int i = 0; i < len; i++) {
            bool isP = true;
            for (int j = 1; j < len; j++) {
                if (i - j >= 0 && i + j < len) {
                    isP = s[i - j] == s[i + j] && isP;
                    if (isP) {
                        if (2 * j + 1 > maxLen) {
                            res = s.substr(i - j, 2 * j + 1);
                            maxLen = 2 * j + 1;
                        }
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }

            isP = true;
            for (int j = 0; j < len; j++) {
                if (i - j >= 0 && i + 1 + j < len) {
                    isP = s[i - j] == s[i + 1 + j] && isP;
                    if (isP) {
                        if (2 * (j + 1) > maxLen) {
                            res = s.substr(i - j, 2 * (j + 1));
                            maxLen = 2 * (j + 1);
                        }
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }

        return res;
    }
};