/// Source URL:  Isomorphic Strings

#include <vector> 
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lenS = s.size();
        int lenT = s.size();

        vector<int> codeS(lenS, 0);
        vector<int> codeT(lenT, 0);

        encode(s, codeS);
        encode(t, codeT);
        for (int i = 0; i < lenS; i++) {
            if (codeS[i] != codeT[i]) {
                return false;
            }
        }
        return true;
    }

    void encode(string &s, vector<int> &res) {
        vector<int> chars(256, 0);

        int count = 1;
        for (int i = 0; i < s.size(); i++) {
            if (chars[s[i]] == 0) {
                res[i] = count;
                chars[s[i]] = count;
                count++;
            }
            else {
                res[i] = chars[s[i]];
            }
        }
    }
};
