#include <vector> 
#include <stack> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        m_curr = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return m_curr != NULL || !m_path.empty();
    }

    /** @return the next smallest number */
    int next() {
        while (m_curr) {
            m_path.push(m_curr);
            m_curr = m_curr->left;
        }
        if (!m_path.empty()) {
            TreeNode *result = m_path.top();
            m_path.pop();
            m_curr = result->right;
            return result->val;
        }
        return 0;
    }

private:
    stack<TreeNode*> m_path;
    TreeNode *m_curr;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/