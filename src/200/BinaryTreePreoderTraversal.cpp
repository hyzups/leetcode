#include <vector> 
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;

        while (root || !s.empty()) {
            if (!root) {
                root = s.top();
                s.pop();
            }
            else {
                res.push_back(root->val);
                if (root->right) {
                    s.push(root->right);
                }
                root = root->left;
            }
        }

        return res;
    }
};