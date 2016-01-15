#include <vector> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;

        fast = reverseList(fast);

        while (head && fast)
        {
            ListNode* temp = fast->next;
            fast->next = head->next;
            head->next = fast;
            head = head->next->next;
            fast = temp;
        }
    }

    ListNode * reverseList(ListNode *node) {

        ListNode *previous = NULL;
        while (node) {
            ListNode *temp = node->next;
            node->next = previous;
            previous = node;
            node = temp;
        }
        return previous;
    }
};

//int main() {
//    Solution s;
//    ListNode l1(1);
//    ListNode l2(2);
//    ListNode l3(3);
//    ListNode l4(4);
//    l1.next = &l2;
//    l2.next = &l3;
//    l3.next = &l4;
//
//    s.reorderList(&l1); 
//}