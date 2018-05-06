#include <vector>
#include <string> 
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {

        if (numerator == 0 || denominator == 0) {
            return "0";
        }
        string res = numerator > 0 ^ denominator > 0 ? "-" : "";

        int64_t numer = abs(numerator);
        int64_t denom = abs(denominator);

        int64_t d = numer / denom;
        res.append(to_string(d));
        int64_t r = numer % denom;

        if (r == 0) {
            return res;
        }

        res.append(".");

        unordered_map<int64_t, int64_t> digitNums;
        while (r != 0) {
            if (digitNums.find(r) == digitNums.end()) {
                digitNums[r] = res.length();
                r = r * 10;
                int64_t num = r / denom;
                res.append(to_string(num));
                r = r % denom;
            }
            else {
                int64_t start = digitNums[r];
                res.insert(start, "(");
                res.append(")");
                break;
            }
        }
        return res;
    }
};

