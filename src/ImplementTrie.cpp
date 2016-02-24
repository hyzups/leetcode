/// Source URL: https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    bool isWord;
    char m_c;
    unordered_map<char, TrieNode*> children;

    // Initialize your data structure here.
    TrieNode(char c) {
        this->m_c = c;
        this->isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode(' ');
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* currentNode = this->root;
        for (int i = 0; i < word.length(); i++) {
            if (currentNode->children.find(word[i]) == currentNode->children.end()) {
                TrieNode *node = new TrieNode(word[i]);
                currentNode->children[word[i]] = node;
                currentNode = node;
            }
            else {
                currentNode = (currentNode->children)[word[i]];
            }
            if (i == word.length() - 1) {
                currentNode->isWord = true;
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        searchHelper(word, false);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        searchHelper(prefix, true);
    }

    bool searchHelper(string word, bool prefixOnly) {
        TrieNode *current = root;
        for (int i = 0; i < word.length(); i++) {
            if (current->children.find(word[i]) == current->children.end()) {
                return false;
            }
            current = current->children[word[i]];
        }

        return  prefixOnly ? true : current->isWord;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");