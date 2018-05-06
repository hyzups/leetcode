#include <string>
#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {

        if (secret.size() != guess.size()) {
            return "0A0B";
        }

        vector<int> sNum(10, 0);
        vector<int> gNum(10, 0);

        int bulls = 0, cows = 0, len = secret.size();
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                cows++;
            }
            else {
                sNum[secret[i] - '0']++;
                gNum[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < len; i++) {
            bulls += min(sNum[i], gNum[i]);
        }

        return to_string(cows) + "A" + to_string(bulls) + "B";
    }
};