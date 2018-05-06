#include <cstdio>
#include <algorithm>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = nums.size();
        return sortedArrayToBST(nums, 0, s);
    }

private:
    TreeNode *sortedArrayToBST(vector<int> &nums, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            TreeNode * root = new TreeNode(nums[m]);
            root->left = sortedArrayToBST(nums, l, m);
            root->right = sortedArrayToBST(nums, m + 1, r);
            return root; 
        }
        return NULL;
    }
};