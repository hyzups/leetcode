#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len = pattern.length();
        vector<int> pVec(26, -1);
        map<string, int> found;

        int pos = 0;

        for (int i = 0; i < len; i++) {
            char c = pattern[i];
            string word = getNextToken(str, pos);
            if (word == "") {
                return false;
            }

            if (pVec[c - 'a'] != -1) {
                if (found.find(word) == found.end()) {
                    return false;
                }
                if (pVec[c - 'a'] != found[word]) {
                    return false;
                }
            }
            else {
                if (found.find(word) != found.end()) {
                    return false;
                }
                pVec[c - 'a'] = found[word] = i;
            }
        }
        return getNextToken(str, pos) == "";
    }

    string getNextToken(string &str, int &pos) {
        while (pos < str.length() && str[pos] == ' ') pos++;
        if (pos == str.length()) {
            return "";
        }

        int start = pos;
        while (pos < str.length() && str[pos] != ' ') pos++;
        return str.substr(start, pos - start);
    }
};