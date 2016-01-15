#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>


using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int len = s.length();
        int i = 0; int j = len - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
            }
            else if (!isalnum(s[j])) {
                j--;
            }
            else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            else {
                i++; j--;
            }
        }

        return true;
    }
};