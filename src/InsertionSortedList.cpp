#include <vector> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode *res = NULL;
        while (head) {
            ListNode *temp = head->next;
            head->next = NULL;
            res = insert(res, head);
            head = temp;
        }

        return res;
    }

    ListNode* insert(ListNode *l1, ListNode *l2)
    {
        if (!l1) {
            return l2;
        }

        ListNode dummy(-1);
        dummy.next = l1;

        ListNode *prev = &dummy;
        while (l1 && l1->val < l2->val) {
            prev = l1;
            l1 = l1->next;
        }

        prev->next = l2;
        l2->next = l1;

        return dummy.next;
    }
};