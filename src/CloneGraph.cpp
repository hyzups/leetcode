#include <vector> 
#include <unordered_map>

using namespace std;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>  m;
        return  dfsGraph(node, m);
    }

    UndirectedGraphNode *dfsGraph(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &m) {
        if (!node) {
            return NULL;
        }

        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        m[node] = newNode;

        for (int i = 0; i < node->neighbors.size(); i++) {
            auto it = m.find((node->neighbors)[i]);
            if (it == m.end()) {
                newNode->neighbors.push_back(dfsGraph(node->neighbors[i], m));
            }
            else {
                newNode->neighbors.push_back(it->second);
            }
        }
        return newNode;
    }
};