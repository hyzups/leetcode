#include <string> 
#include <vector> 
#include <algorithm>

using namespace std;

class Comparator {
public:
    bool operator()(const string &a, const string b) {
        return a + b > b + a;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto i : nums) {
            strs.push_back(to_string(i));
        }
        sort(strs.begin(), strs.end(), Comparator());

        string res;
        for (auto str : strs) {
            res += str;
        }

        return res[0] == '0' ? "0" : res;
    }
};