#include <vector> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd(-1);
        ListNode even(-1);
        ListNode *p1 = &odd, *p2 = &even;

        while (head) {
            p1->next = head;  p1 = p1->next;
            head = head->next;

            p1->next = NULL;
            if (head) {
                p2->next = head; p2 = p2->next;
                head = head->next;
                p2->next = NULL;
            }
        }

        p1->next = even.next;
        return odd.next;
    }
};