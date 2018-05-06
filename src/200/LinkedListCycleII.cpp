#include <vector> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return NULL;
        }

        ListNode *slow = head, *fast = head;

        do {
            if (!fast || !fast->next) {
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        ListNode *result = head;
        while (result != slow) {
            result = result->next;
            slow = slow->next;
        }
        return result;
    }
};