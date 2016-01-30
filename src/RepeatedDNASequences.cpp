#include <vector> 
#include <string> 
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> dict;
        vector<string> res;
        int len = s.length();
        for (int i = 0; i < len - 9; i++) {
            string sub = s.substr(i, 10);
            dict[sub]++;
            if (dict[sub] == 2) {
                res.push_back(sub);
            }
        }
        return res;
    }
};