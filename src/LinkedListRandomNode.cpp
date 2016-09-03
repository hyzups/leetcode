#include<cmath>
#include<cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* m_head;
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		this->m_head = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		if (!m_head) {
			return -1;
		}

		int res = m_head->val;
		int i = 2;
		ListNode *p = m_head->next;
		while (p) {
			int r = rand() % i;
			if (r == 0) {
				res = p->val;
			}
			p = p->next, i++;
		}
		return res;

	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/