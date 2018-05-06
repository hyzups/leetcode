/// Source URL: https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {

        int level = 0;
        vector<int> res;
        rightSideViewRe(root, 0, res);
        return res;
    }

    void rightSideViewRe(TreeNode *node, int level, vector<int> &res) {
        if (!node) {
            return;
        }

        if (res.size() <= level) {
            res.push_back(node->val);
        }

        rightSideViewRe(node->right, level + 1, res);
        rightSideViewRe(node->left, level + 1, res);
    }
};