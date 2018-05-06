#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct MyListNode {
    int val;
    int key; 
    MyListNode *prev;
    MyListNode *next;
    MyListNode(int v, int k) {
        this->val = v;
        this->key = k; 
        prev = next = NULL;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {
        m_size = 0;
        head = new MyListNode(-1, -1);
        tail = new MyListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it = keyMap.find(key);
        if (it != keyMap.end()) {
            MyListNode *node = it->second;
            detach(node);
            attach(node);
            return node->val;
        }
        return -1;
    }

    void set(int key, int value) {
        if (keyMap.find(key) == keyMap.end()) {
            MyListNode *node = new MyListNode(value, key);
            keyMap[key] = node;
            if (m_size == m_capacity) {
                MyListNode *toDelete = detach(tail->prev); 
                keyMap.erase(toDelete->key);
                delete toDelete; 
            }
            else {
                m_size++;
            }
            attach(node);
        }
        else {
            MyListNode *node = keyMap[key];
            node->val = value;
            detach(node);
            attach(node);
        }
    }

private:

    MyListNode* detach(MyListNode *node) {

        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = node->prev = NULL;

        return node;
    }

    void attach(MyListNode *node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }

    int m_capacity;
    int m_size;
    MyListNode *head, *tail;
    unordered_map<int, MyListNode*> keyMap;
};

//
//
//int main()
//{
//    LRUCache cache(1);
//
//    cache.set(2, 1);
//    cache.get(2);
//    cache.set(3, 2);
//    cache.get(2);
//    cache.get(3);
//}