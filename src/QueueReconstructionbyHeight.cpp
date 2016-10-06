#include <vector>
#include <algorithm>
#include <string> 

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {

        sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        int len = people.size();

    }
};