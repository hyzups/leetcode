#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        int len = beginWord.size();

        wordList.erase(beginWord);
        wordList.insert(endWord);

        queue<string> curr, next;
        curr.push(beginWord);

        map<string, vector<string>> prevs;
        bool found = false;

        while (true) {
            while (!curr.empty()) {
                string word = curr.front();
                curr.pop();

                for (int i = 0; i < len; i++) {
                    string temp = word;
                    for (int j = 0; j < 26; j++) {
                        if (word[i] == j + 'a') {
                            continue;
                        }
                        temp[i] = 'a' + j;
                        if (temp == endWord) {
                            found = true;
                        }
                        if (wordList.find(temp) != wordList.end()) {
                            auto it = prevs.find(temp);
                            if (it != prevs.end()) {
                                it->second.push_back(word);
                            }
                            else {
                                prevs[temp].push_back(word);
                                next.push(temp);
                            }
                        }
                    }
                }
            }

            if (found) {
                break;
            }
            else {
                while (!next.empty()) {
                    string word = next.front();
                    next.pop();
                    wordList.erase(word);
                    curr.push(word);
                }
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        path.push_back(endWord);
        buildPath(res, prevs, path, endWord, beginWord);
        return res;
    }

    void buildPath(vector<vector<string>> &res, map<string, vector<string>> &prevs, vector<string> &path, string &target, string &endWord) {
        if (target == endWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }

        auto it = prevs.find(target);

        for (auto &w : it->second) {
            path.push_back(w);
            buildPath(res, prevs, path, w, endWord);
            path.pop_back();
        }
    }
};