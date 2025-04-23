#define node ListNode
class Solution {
public:
	node* deleteDuplicates(node* head) {
		node* h = NULL, * t = NULL;
		// ek bhi node nahi hai, ya ek hi node hai toh duplicates possible nhi hai
		if (head == NULL || head->next == NULL) return head;

		while (head and head->next) {
			if (head->val != head->next->val) {
				if (h == NULL) {
					h = t = head;
					head = head->next;
					t->next = NULL;
				}
				else {
					t->next = head;
					t = t->next;
					head = head->next;
					t->next = NULL;
				}
			}
			else {
				int val = head->val;
				while (head and head->val == val) {
					head = head->next;
				}
			}
		}

		t->next = head;
		return h;
	}


};