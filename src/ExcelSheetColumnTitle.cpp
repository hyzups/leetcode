#include <string> 

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            int tmp = (n - 1) % 26;
            res.insert(res.begin(), 'A' + tmp);
            n = (n - 1) / 26;
        }
        return res;
    }
};

