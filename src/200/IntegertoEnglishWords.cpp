#include <string> 
#include <vector>

using namespace std;

const string THOUSANDS[] = { "", " Thousand", " Million", " Billion" };

const string LESS_THEN_TWENTY[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

const string TENS[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

class Solution {
public:
    string numberToWords(int num) {

        if (num == 0) {
            return "Zero";
        }
        string res = "";
        int k = 0;
        while (num > 0) {
            if (num % 1000 > 0) {
                res = helper(num % 1000) + THOUSANDS[k] + res;
            }
            num /= 1000;
            k++;
        }
        return res.substr(1);
    }

    string helper(int num) {
        if (num == 0) {
            return "";
        }
        else if (num < 20) {
            return " " + LESS_THEN_TWENTY[num];
        }
        else if (num < 100) {
            return " " + TENS[num / 10] + helper(num % 10);
        }
        else {
            return helper(num / 100) + " Hundred" + helper(num % 100);
        }
    }
};