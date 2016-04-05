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
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        flattenRecursively(root, prev);
    }

    void flattenRecursively(TreeNode* node, TreeNode*& prev) {
        if (!node) {
            return;
        }
        TreeNode *l = node->left;
        TreeNode *r = node->right;
        if (prev) {
            prev->right = node;
        }
        node->left = node->right = NULL;
        prev = node;
        flattenRecursively(l, prev);
        flattenRecursively(r, prev);
    }
};
