#include <vector> 
#include <string> 
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> path;

        map<string, multiset<string>> g;
        for (auto& p : tickets) {
            g[p.first].insert(p.second);
        }

        string start("JFK");

        visit(start, g, path);
        vector<string> res(path.rbegin(), path.rend());
        return res;
    }

    void visit(string &curr, map<string, multiset<string>> &g, vector<string> &path) {
        while (g[curr].size() > 0) {
            string next = *g[curr].begin();
            g[curr].erase(g[curr].begin());
            visit(next, g, path);
        }
        path.push_back(curr);
    }
};