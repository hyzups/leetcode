#include <cstdio>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode *node, int p) {
        if (!node) {
            return 0;
        }

        int currNumber = p * 10 + node->val;
        if (!node->left && !node->right) {
            return currNumber;
        }

        return  sumNumbers(node->left, currNumber) + sumNumbers(node->right, currNumber);
    }
};