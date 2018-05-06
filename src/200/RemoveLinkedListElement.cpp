/// Source URL: http://articles.leetcode.com/how-to-pretty-print-binary-tree/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode temp(-1);
        temp.next = head;
        ListNode *prev = &temp, *curr = head;
        while (curr) {
            if (curr->val != val) {
                prev->next = curr;
                prev = prev->next;
            }
            curr = curr->next;
        }

        prev->next = NULL;
        return temp.next;
    }
};