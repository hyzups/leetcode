/// Source URL: https://leetcode.com/problems/count-complete-tree-nodes/

#include <vector> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int lHeight = getLeftTreeHeight(root->left);
        int rHeight = getLeftTreeHeight(root->right);
        return lHeight == rHeight ? pow(2, lHeight) + countNodes(root->right) : pow(2, rHeight) + countNodes(root->left);
    }

    int getLeftTreeHeight(TreeNode *n) {
        int res = 0;
        while (n) {
            n = n->left;
            res++;
        }
        return res;
    }
};