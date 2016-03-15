/// Source URL: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

#include <string> 

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int pos = 0;

        int res = validateTree(preorder, pos);
        return res && pos == preorder.length();
    }

    bool validateTree(string &preorder, int &pos) {
        if (pos < preorder.length()) {
            if (preorder[pos] == '#') {
                while (preorder[pos] != ',' && pos < preorder.length()) pos++;
                if (preorder[pos] == ',') pos++;
                return true;
            }
            else {
                while (preorder[pos] != ',' && pos < preorder.length()) pos++;
                if (preorder[pos] == ',') pos++;
                return validateTree(preorder, pos) && validateTree(preorder, pos);
            }
        }
        else {
            return false;
        }
    }
};
