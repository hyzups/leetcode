#include <string>
#include <vector> 
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> tree;
        unordered_set<string> found;

        for (int i = 0; i < equations.size(); i++) {
            tree[equations[i].first][equations[i].second] = values[i];
            tree[equations[i].second][equations[i].first] = 1.0 / values[i];
            found.insert(equations[i].first);
            found.insert(equations[i].second);
        }

        vector<double> res;

        for (auto &p : queries) {
            if (found.find(p.first) == found.end() || found.find(p.second) == found.end()) {
                res.push_back(-1.0);
                continue;
            }
            vector<double> path;
            unordered_set<string> visited;
            if (searchResult(tree, visited, p.first, p.second, path)) {
                double ans = 1.0;
                for (auto d : path) {
                    ans *= d;
                }
                res.push_back(ans);
            }

            else {
                res.push_back(-1.0);
            }

        }

        return res;
    }

    bool searchResult(unordered_map<string, unordered_map<string, double>> &t, unordered_set<string> &visited, const string start, const string &end, vector<double> &result) {
        if (start == end) {
            return true;
        }

        visited.insert(start);

        auto m = t.find(start);

        if (m == t.end())
        {
            return false;
        }

        for (auto k : m->second) {
            if (visited.find(k.first) == visited.end()) {
                result.push_back(k.second);
                if (searchResult(t, visited, k.first, end, result)) {
                    return true;
                }
                result.pop_back();
            }
        }
        return false;
    }

};
