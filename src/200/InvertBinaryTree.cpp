/// Source URL: https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root) {

        if (!root) {
            return NULL;
        }

        invertTree(root->left);
        invertTree(root->right);

        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;
        return root;
    }
};