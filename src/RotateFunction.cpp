#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int f = 0;
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            f += i * A[i];
            sum += A[i];
        }

        int res = f;

        for (int i = 1; i < A.size(); i++) {
            f = f - sum + A.size() * A[i - 1];
            res = max(f, res);
        }

        return res;
    }
};