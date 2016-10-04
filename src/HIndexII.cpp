#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int l = 0, r = len - 1, res = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (len - mid >= citations[mid]) {
                res = len - mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;

    }
};