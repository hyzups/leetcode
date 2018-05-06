//#include <vector>
//#include <algorithm>
//#include <functional>
//#include <numeric>
//
//using namespace std;
//
//class Solution {
//public:
//    int bulbSwitch(int n) {
//
//        vector<int> opened(n, 1);
//        for (int i = 2; i <= n; i++)
//        {
//            for (int j = i; j <= n; j += i)
//            {
//                opened[j - 1] = opened[j - 1] == 1 ? 0 : 1;
//            }
//        }
//
//        return accumulate(opened.begin(), opened.end(), 0);
//    }
//};

#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return floor(sqrt(n));
    }
};