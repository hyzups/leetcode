#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
public:
    vector<int> neighbors;
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<Node> g(n);
        vector<int> counters(n, 0);

        for (auto e : edges) {
            g[e.first].neighbors.push_back(e.second);
            g[e.second].neighbors.push_back(e.first);
            counters[e.first]++;
            counters[e.second]++;
        }

        queue<int> leaves;

        for (int i = 0; i < n; i++) {
            if (counters[i] <= 1) {
                leaves.push(i);
            }
        }

        int total = n; 
        while (total > 2) {
            int i = leaves.size();
            total -= i; 

            while (i > 0) {
                Node node = g[leaves.front()];
                leaves.pop();

                for (auto neighbor : node.neighbors) {
                    if (--counters[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
                --i;
            }
        }

        vector<int> res; 
        while (!leaves.empty()) {
            res.push_back(leaves.front()); 
            leaves.pop(); 
        }

        sort(res.begin(), res.end());
        return res;
    }
};
//
//int main() {
//    Solution s; 
//    vector<pair<int, int>> values; 
//    values.push_back(pair<int, int>(3, 0)); 
//    values.push_back(pair<int, int>(3, 1));
//    values.push_back(pair<int, int>(3, 2));
//    values.push_back(pair<int, int>(3, 4));
//    values.push_back(pair<int, int>(4, 5));
//    s.findMinHeightTrees(6, values); 
//
//}
//
