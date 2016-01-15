#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if (!head || !head->next) {
            return head;
        }

        int len = countLength(head);

        for (int step = 1; step < len; step <<= 1) {
            ListNode dummy(-1);
            ListNode *tail = &dummy;
            ListNode *curr = head, *first, *second;
            while (curr) {
                first = curr;
                curr = splitList(curr, step);
                second = curr;
                curr = splitList(curr, step);
                tail = mergeList(first, second, tail);
            }
            head = dummy.next;
        }

        return head;
    }

    ListNode *mergeList(ListNode *l1, ListNode *l2, ListNode *head) {
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = l1 != NULL ? l1 : l2;
        while (head->next != NULL) {
            head = head->next;
        }
        return head;

    }

    ListNode* splitList(ListNode *node, int count) {
        while (node && --count > 0) {
            node = node->next;
        }
        if (node) {
            ListNode *res = node->next;
            node->next = NULL;
            return res;
        }
        return NULL;
    }

    int countLength(ListNode *node) {
        int i = 0;
        while (node) {
            ++i;
            node = node->next;
        }
        return i;
    }
};