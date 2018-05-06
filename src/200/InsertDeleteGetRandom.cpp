#include <vector> 
#include <cmath>
#include <unordered_map>

using namespace std;

struct Node {
    int m_vecIndex;
    int m_val;
};

class RandomizedSet {
private:
    vector<int> m_mapIndex;
    unordered_map<int, Node*> m_map;
public:
    /** Initialize your data structure here. */
    RandomizedSet() :m_mapIndex(vector<int>()), m_map(unordered_map<int, Node*>()) {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m_map.find(val) != m_map.end()) {
            return false;
        }

        Node *n = new Node();
        n->m_val = val;
        n->m_vecIndex = m_mapIndex.size();
        m_mapIndex.push_back(val);
        m_map[val] = n;

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m_map.find(val) == m_map.end()) {
            return false;
        }

        Node *n = m_map[val];
        if (n->m_vecIndex != m_mapIndex.size() - 1) {
            int key = m_mapIndex.back();
            m_map[key]->m_vecIndex = n->m_vecIndex;
            m_mapIndex[n->m_vecIndex] = key;
        }
        m_mapIndex.pop_back();
        m_map.erase(val);
        delete n;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (m_mapIndex.size() == 0) {
            return -1;
        }
        int r = rand() % m_mapIndex.size();
        return m_map[m_mapIndex[r]]->m_val;
    }
};
