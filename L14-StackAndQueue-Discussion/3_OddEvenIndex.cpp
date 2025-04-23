#define node ListNode
class Solution {
public:

	node* oddEvenList(node* head) {
		node* oh = NULL, *ot = NULL, *eh = NULL, *et = NULL;
		int i = 0;
		while (head) {
			if ( i % 2 == 0) {
				if (oh == NULL) {
					oh = ot = head;
					head = head->next;
					ot->next = NULL;
				}
				else {
					ot->next = head;
					ot = head;
					head = head->next;
					ot->next = NULL;
				}
			}
			else {
				if (eh == NULL) {
					eh = et = head;
					head = head->next;
					et->next = NULL;
				}
				else {
					et->next = head;
					et = head;
					head = head->next;
					et->next = NULL;
				}
			}

			i++;
		}

		if (oh != NULL) {
			ot->next = eh;
			return oh;
		}
		else {
			return eh;
		}

	}

};