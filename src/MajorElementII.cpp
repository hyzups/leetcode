#include<vector> 
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnta = 0, cntb = 0, a, b;
        for (auto x : nums) {
            if (x == a) {
                cnta++;
            }
            else if (x == b) {
                cntb++;
            }
            else if (cnta == 0) {
                a = x;
                cnta = 1;
            }
            else if (cntb == 0) {
                b = x;
                cntb = 1;
            }
            else {
                cnta--;
                cntb--;
            }
        }

        cnta = 0;
        cntb = 0;

        for (auto x : nums) {
            if (x == a) cnta++;
            else if (x == b) cntb++;
        }

        vector<int> res;
        if (cnta > nums.size() / 3) res.push_back(a);
        if (cntb > nums.size() / 3) res.push_back(b);
        return res;
    }
};