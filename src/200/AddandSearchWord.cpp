/// Source URL: https://leetcode.com/problems/add-and-search-word-data-structure-design/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TrieNode
{
    TrieNode* children[26];
    bool isWord;

    TrieNode()
    {
        memset(children, 0, sizeof(children));
        isWord = false;
    }
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->children[word[i] - 'a'] != NULL) {
            }
            else {
                curr->children[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[word[i - 'a']];
        }
        curr->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode *curr = root;
    }

    bool search(string &word, int i, TrieNode *curr) {
        if (!curr) {
            return false;
        }
        if (i == word.length() && curr->isWord) {
            return true;
        }

        if (word[i] != '.') {
            if (curr->children[word[i] - 'a'] != NULL) {
                return search(word, i + 1, curr->children[word[i] - 'a']);
            }
            else {
                return false;
            }
        }
        else {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] && search(word, i + 1, curr->children[i])) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");