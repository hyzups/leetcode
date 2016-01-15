#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *curr = head;
        while (curr) {
            RandomListNode *temp = new RandomListNode(curr->label);
            temp->random = curr->random;
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        };

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        RandomListNode dummy(-1);
        curr = &dummy;
        while (head) {
            curr->next = head->next;
            head->next = curr->next->next;
            curr = curr->next;
            head = head->next;
        }
        return dummy.next;
    }
};