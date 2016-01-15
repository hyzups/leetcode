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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *previous = NULL;

        while (root || !s.empty()) {
            if (!root) {
                TreeNode *temp = s.top();
                if (!temp->right || temp->right == previous) {
                    res.push_back(temp->val);
                    previous = temp;
                    s.pop();
                }
                else {
                    root = temp->right;
                }
            }
            else {
                s.push(root);
                root = root->left;
            }
        }
        return res;
    }
};