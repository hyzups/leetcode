#include <string> 
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, len1 = version1.length(), len2 = version2.length();
        while (i < len1 || j < len2) {
            int a = 0;
            while (i < len1 && version1[i] != '.') {
                a = 10 * a + version1[i] - '0';
                i++;
            }
            i++; 
            int b = 0;
            while (j < len2 && version2[j] != '.') {
                b = 10 * b + version2[j] - '0';
                j++;
            }
            j++; 
            if (a < b) {
                return -1;
            }
            else if (a > b) {
                return 1;
            }
        }
        return 0;
    }
};