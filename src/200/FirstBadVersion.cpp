// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int res = n;

        int l = 0, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};