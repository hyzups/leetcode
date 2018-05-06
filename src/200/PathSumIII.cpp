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
    int pathSum(TreeNode* root, int sum) {
        vector<int> p;
        return pathSum(root, p, sum);
    }

    int pathSum(TreeNode* root, vector<int>& path, int sum) {
        if (!root) {
            return 0;
        }
        int res = 0;
        path.push_back(root->val);
        int curr = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            curr += path[i];
            if (curr == sum) {
                res++;
            }
        }

        if (root->left) {
            res += pathSum(root->left, path, sum);
        }
        if (root->right) {
            res += pathSum(root->right, path, sum);
        }

        path.pop_back();

        return res;
    }
};