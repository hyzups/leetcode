#include <cstdio>
#include <vector> 
#include <algorithm>
#include <functional>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = getLength(head);

        return sortedListToBST(head, len);
    }
private:
    int getLength(ListNode *node) {
        int res = 0;
        while (node) {
            res++;
            node = node->next;
        }
        return res;
    }

    TreeNode* sortedListToBST(ListNode* &curr, int len) {
        if (len == 0) {
            return nullptr;
        }
        else if (len == 1) {
            TreeNode *root = new TreeNode(curr->val);
            curr = curr->next;
            return root;
        }
        else {
            int m = len / 2;
            TreeNode *l = sortedListToBST(curr, m);
            TreeNode *root = new TreeNode(curr->val);
            root->left = l;
            curr = curr->next;
            root->right = sortedListToBST(curr, len - m - 1);
            return root;
        }
    }
};