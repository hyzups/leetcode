#include <string>
#include <cstring>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream strStream;
        serializeInternally(root, strStream);
        return strStream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream inStream(data);
        return deserializeInternally(inStream);
    }

private:

    void serializeInternally(TreeNode *root, stringstream& stream) {
        if (!root) {
            stream << "# ";
            return;
        }

        stream << root->val << " ";
        serializeInternally(root->left, stream);
        serializeInternally(root->right, stream);
    }

    TreeNode *deserializeInternally(stringstream &inStream) {
        string temp;
        inStream >> temp;
        if (temp.length() == 1 && temp[0] == '#') {
            return NULL;
        }
        int val = atoi(temp.c_str());
        TreeNode *tn = new TreeNode(val);
        tn->left = deserializeInternally(inStream);
        tn->right = deserializeInternally(inStream);
        return tn;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));