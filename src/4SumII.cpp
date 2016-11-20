/*
 * Source URL: https://leetcode.com/problems/4sum-ii/
 */
#include <vector> 
#include <unordered_map>

using namespace std;

unordered_map<int, int> counts;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        int len = A.size();
  

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                counts[A[i] + B[j]]++;
            }
        }

        int res = 0;

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int sum = C[i] + D[j];
                if (counts[-sum] > 0) {
                    res += counts[-sum];
                }
            }
        }

        return res;
    }
};