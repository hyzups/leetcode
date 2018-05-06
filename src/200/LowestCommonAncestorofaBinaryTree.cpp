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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p == root || q == root) {
            return root;
        }

        TreeNode *l = lowestCommonAncestor(root->right, p, q);
        TreeNode *r = lowestCommonAncestor(root->left, p, q);

        if (l  && r) {
            return root;
        }
        else {
            return l != NULL ? l : r;
        }
    }
};