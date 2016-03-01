/// Source URL: https://leetcode.com/problems/word-search-ii/

#include <vector> 
#include <string>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];

    TrieNode() {
        memset(children, 0, sizeof(TrieNode*) * 26);
        isWord = false;
    }
};

class Solution {
private:
    TrieNode *root;

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0) {
            return vector<string>();
        }
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            insertWord(words[i]);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (root->children[board[i][j] - 'a']) {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    string found = "";
                    found.push_back(board[i][j]);
                    visited[i][j] = true;
                    searchWord(i, j, board, visited, root, res, found);
                }
            }
        }
        return res;
    }

    void insertWord(string &word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (!curr->children[word[i] - 'a']) {
                curr->children[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->isWord = true;
    }

    void searchWord(int m, int n, vector<vector<char>> &board, vector<vector<bool>> &visited, TrieNode *curr, vector<string> &res, string &found) {
        TrieNode *next = curr->children[board[m][n] - 'a'];
        if (!next) {
            return;
        }

        if (next->isWord) {
            res.push_back(found);
            next->isWord = false;
        }

        curr = next;

        for (int i = 0; i < 4; i++) {
            int x = m + dx[i];
            int y = n + dy[i];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                if (visited[x][y]) {
                    continue;
                }
                if (curr->children[board[x][y] - 'a']) {
                    visited[x][y] = true;
                    found.push_back(board[x][y]);
                    searchWord(x, y, board, visited, curr, res, found);
                    found.pop_back();
                    visited[x][y] = false;
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        { 'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = { "oath", "pea", "eat", "rain" };
    Solution s;
    s.findWords(board, words);
}