#include <string> 
#include <vector> 
#include <algorithm>

using namespace std; 

class Solution {
public:
    string reverseVowels(string s) {
        vector<bool> isVowel(256, 0);
        isVowel['a'] = isVowel['e'] = isVowel['o'] = isVowel['u'] = isVowel['i'] = true; 
        isVowel['A'] = isVowel['E'] = isVowel['O'] = isVowel['U'] = isVowel['I'] = true;

        int len = s.length(); 
        int start = 0, end = len - 1; 
        while (start < end) {
            while (!isVowel[s[start]] && start < end) start++; 
            while (!isVowel[s[end]] && end >= 0) end--; 
            if (start < end) {
                swap(s[start], s[end]); 
                start++; 
                end--; 
            }
        }
        return s; 

    }
};