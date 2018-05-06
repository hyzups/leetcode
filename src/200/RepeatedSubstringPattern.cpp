#include <string> 

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        size_t len = str.length();

        for (size_t i = 0; i < len / 2; i++) {

            string s = str.substr(0, i + 1);
            if (isReaptedString(str, s)) {
                return true;
            }
        }

        return false;
    }

    bool isReaptedString(string &s, string &subs) {
        for (size_t i = subs.length(); i < s.length(); i += subs.length()) {
            for (int j = 0; j < subs.length(); j++) {
                if (i + j >= s.length() || subs[j] != s[i + j]) {
                    return false;
                }
            }
        }

        return true;
    }
};