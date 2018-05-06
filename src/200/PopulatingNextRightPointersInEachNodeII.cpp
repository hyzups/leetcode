#include<algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {


        if (!root) {
            return;
        }

        queue<TreeLinkNode*> q;

        q.push(root);
        q.push(NULL);

        while (!q.empty()) {

            TreeLinkNode *prev = NULL;

            while (true)
            {
                TreeLinkNode *curr = q.front();
                q.pop();
                if (curr == NULL) {
                    break;
                }

                if (curr->left) {
                    if (prev != NULL) {
                        prev->next = curr->left;
                    }
                    prev = curr->left;
                    q.push(curr->left);
                }
                if (curr->right) {
                    if (prev != NULL) {
                        prev->next = curr->right;
                    }
                    prev = curr->right;
                    q.push(curr->right);
                }
            }

            if (!q.empty()) {
                q.push(NULL);
            }
        }
    }
};