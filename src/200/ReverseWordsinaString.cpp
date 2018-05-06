#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {

        reverse(s.begin(), s.end());

        int targetIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                if (targetIndex != 0) {
                    s[targetIndex++] = ' ';
                }
                int startIndex = i, j = i;
                while (s[j] != ' ' && j < s.length()) {
                    s[targetIndex++] = s[j++];
                }
                reverse(s.begin() + startIndex, s.end() + targetIndex);
                i = j;
            }
        }
        s.erase(s.begin() + targetIndex, s.end());
    }
};