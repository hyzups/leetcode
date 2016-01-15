#include<cstdio>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

enum TokenType {
    INVALID,
    WHITESPACE,
    SIGN,
    DIGIT,
    DOT,
    EXP
};

class Solution {



public:
    bool isNumber(string s) {

        int fsm[][6] = {
            { -1, 0,  1, 2, 3,   -1 },    // Start state 
            { -1, 0, -1, 2, 3,   -1 },    // Starting SIGN
            { -1, 0, -1, 2, 4,   5 },    // DIGIT  
            { -1,-1, -1, 3, -1,  -1 },    // DOT  
            { -1, 8, -1, 4, -1,   5 },    // DOT AND DIGIT
            { -1, -1, 6, 7, -1,  -1 },    //  EXP
            { -1, 1, -1,7,  -1,  -1 },    //  SIGN AND EXP
            { -1, 8, -1, 7, -1,  -1 },    // 
            { -1, 8, -1, -1, -1, -1 } //END
        };


        int len = s.size();
        int state = 0;
        for (int i = 0; i < len; i++) {
            TokenType t = getTokenType(s[i]);
            state = fsm[state][t];
            if (state == -1) {
                break;
            }
        }

        return state == 2 || state == 4 || state == 7 || state == 8;
    }

    TokenType getTokenType(char c)
    {
        switch (c)
        {
        case 'e':
        case 'E':
            return EXP;
        case '+':
        case '-':
            return SIGN;
        case '.':
            return DOT;
        case ' ':
            return WHITESPACE;
        default:
            if (isdigit(c)) {
                return DIGIT;
            }
            return INVALID;
        }

    }
};