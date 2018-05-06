#include <string> 
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> vals;
        getTreePath(root, res, vals);
        return res;
    }

    void getTreePath(TreeNode* node, vector<string> &res, vector<int>& vals) {
        if (!node) {
            return;
        }
        vals.push_back(node->val);

        if (!node->left && !node->right) {
            string s;
            for (int i = 0; i < vals.size(); i++) {
                s += ((i == 0) ? "" : "->") + to_string(vals[i]);
            }
            res.push_back(s);
        }
        else {
            if (node->left) {
                getTreePath(node->left, res, vals);
            }
            if (node->right) {
                getTreePath(node->right, res, vals);
            }
        }
        vals.pop_back();
    }
};