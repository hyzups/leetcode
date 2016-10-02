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
    int kthSmallest(TreeNode* root, int k) {
        int res;

        kthSmallest(root, k, res);

        return res;
    }

    bool kthSmallest(TreeNode *root, int& k, int& res) {
        if (!root) {
            return false;
        }

        if (kthSmallest(root->left, k, res)) {
            return true;
        }

        if (k == 1) {
            res = root->val;
            return true;
        }
        return kthSmallest(root->right, --k, res);
    }
};