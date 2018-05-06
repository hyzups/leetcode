#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int lenA = 0, lenB = 0;

        while (pA) {
            lenA++;
            pA = pA->next;
        }

        while (pB) {
            lenB++;
            pB = pB->next;
        }

        if (!lenA || !lenB) {
            return NULL;
        }

        pA = headA;
        pB = headB;
        if (lenA > lenB) {
            while (lenA > lenB) {
                pA = pA->next;
                lenA--;
            }
        }
        else {
            while (lenB > lenA) {
                pB = pB->next;
                lenB--;
            }
        }

        while (pA && pB && pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};