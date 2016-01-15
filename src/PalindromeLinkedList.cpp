#include <vector>
#include <algorithm>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) {
            return true;
        }

        ListNode *pFirst = head, *pSecond = head->next;

        while (pSecond->next && pSecond->next->next) {
            pFirst = pFirst->next;
            pSecond = pSecond->next->next;
        }

        pSecond = pFirst->next;
        pFirst->next = NULL;

        pFirst = head;
        pSecond = reverseList(pSecond);


        while (pFirst && pSecond) {
            if (pFirst->val != pSecond->val) {
                return false;
            }
            pFirst = pFirst->next;
            pSecond = pSecond->next;
        }

        return true;
    }

    ListNode *reverseList(ListNode *node) {

        ListNode *pHead = NULL, *pTemp = NULL; 

        while (node) {
            pTemp = node->next; 
            node->next = pHead; 
            pHead = node; 
            node = pTemp; 
        }
        return pHead; 
    }
};