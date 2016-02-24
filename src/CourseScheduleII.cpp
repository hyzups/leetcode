/// Source URL: https://leetcode.com/problems/course-schedule-ii/

#include <vector> 
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        stack<int> order;
        vector<int> visited(numCourses);
        vector<vector<int>> g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!topological(i, g, visited, order)) {
                    return vector<int>();
                }
            }
        }

        vector<int> res;
        while (!order.empty()) {
            res.push_back(order.top());
            order.pop();
        }
        return res;
    }

    bool topological(int v, vector<vector<int>> &g, vector<int> &visited, stack<int> &order) {
        visited[v] = 1;
        for (int i = 0; i < g[v].size(); i++) {
            if (visited[g[v][i]] == 1) {
                return false;
            }
            else if (!visited[g[v][i]]) {
                if (!topological(g[v][i], g, visited, order)) {
                    return false;
                }
            }
        }
        visited[v] = 2;
        order.push(v);
        return true;
    }
};