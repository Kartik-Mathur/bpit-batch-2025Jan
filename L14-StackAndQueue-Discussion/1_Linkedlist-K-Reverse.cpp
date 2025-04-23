#define ListNode node
class Solution {
public:
	node* reverseLL(node*head, int k) {
		node* c = head, *p = NULL, *n;

		for (int i = 0; i < k; ++i)
		{
			n = c->next;
			c->next = p;
			p = c;
			c = n;
		}

		return p; // We are expected to return the newHead after reversal of LL
	}

	node* reverseKGroup(node* head, int k) {
		// Create temp to prevent memory leak
		node* temp = head, *og = NULL, *p = NULL;

		while (true) {
			// 1. Jump karwaao temp ko k times, only and only if temp can jump k times

			int jumpCnt = 0;
			while (jumpCnt < k and temp != NULL) {
				temp = temp->next;
				jumpCnt++;
			}

			if (jumpCnt == k) {
				node* nH = reverseLL(head, k);
				if (og == NULL) og = nH;
				head->next = temp;
				if (p) p->next = nH;
				p = head;
				head = temp;
			}
			else break;
		}

		return og;
	}
};






























