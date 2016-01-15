#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> visited;
        if (beginWord == endWord || beginWord.length() != endWord.length()) {
            return 0;
        }
        queue<pair<string, int>> curr;
        wordList.insert(endWord);

        curr.push(pair<string, int>(beginWord, 0));
        int len = beginWord.length();

        while (!curr.empty()) {
            pair<string, int> temp = curr.front();
            curr.pop();

            for (int i = 0; i < len; i++) {
                for (int j = 0; j < 26; j++) {
                    if (j + 'a' == temp.first[i]) {
                        continue;
                    }

                    string word = temp.first;
                    word[i] = j + 'a';
                    if (wordList.find(word) == wordList.end()) {
                        continue;
                    }
                    if (word == endWord) {
                        return temp.second + 1;
                    }
                    curr.push(pair<string, int>(word, temp.second + 1));
                    wordList.erase(word);
                }
            }

        }
        return 0;
    }
};