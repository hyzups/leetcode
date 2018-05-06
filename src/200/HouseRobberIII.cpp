#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        int res;

        return robRe(root, res);
    }

    int robRe(TreeNode *root, int &notInluce) {
        if (!root) {
            notInluce = 0;
            return 0;
        }

        int leftNotInclude;
        int rightNotInclude;

        int leftResult = robRe(root->left, leftNotInclude);
        int rightResult = robRe(root->right, rightNotInclude);

        notInluce = leftResult + rightResult;

        int res = root->val + leftNotInclude + rightNotInclude;
        return max(res, notInluce);
    }
};