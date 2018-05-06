#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> counts(len + 1, 0);

        for (int i = 0; i < len; i++) {
            if (citations[i] >= len) {
                counts[len]++;
            }
            else {
                counts[citations[i]]++;
            }
        }

        int count = 0;

        for (int i = len; i >= 0; --i) {

            count += counts[i];
            if (count >= i) {
                return i;
            }
        }

        return -1;

    }
};