#include <vector>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<int> res;

        for (int i = 1; i < 10; i++) {
            dfs(i, n, res);
        }
        return res;
    }

    void dfs(int curr, int n, vector<int>& res) {
        if (curr <= n) {
            res.push_back(curr);
        }

        for (int i = 0; i < 10; i++) {
            if (curr * 10 + i <= n) {
                dfs(curr * 10 + i, n, res);
            }
        }
    }
};