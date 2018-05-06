/// Source URL: https://leetcode.com/problems/course-schedule/

#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<vector<int>> g(numCourses);;
        for (auto pair : prerequisites) {
            g[pair.second].push_back(pair.first);
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!topological(i, g, visited)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool topological(int v, vector<vector<int>> &g, vector<int> &visited) {
        visited[v] = 1;
        for (int i = 0; i < g[v].size(); i++) {
            if (visited[g[v][i]] == 1) {
                return false;
            }
            else if (visited[g[v][i]] == 2) {
                continue;
            }
            else {
                if (!topological(g[v][i], g, visited)) {
                    return false;
                }
            }
        }
        visited[v] = 2;
        return true;
    }
};