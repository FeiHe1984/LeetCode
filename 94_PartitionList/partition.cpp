/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		if (head == NULL) return NULL;

		ListNode* dummy1 = new ListNode(0);
		ListNode* dummy2 = new ListNode(0);

		ListNode* cur1 = dummy1;
		ListNode* cur2 = dummy2;

		while (head != NULL){
			if (head->val < x){
				cur1->next = head;
				cur1 = cur1->next;
			}
			else{
				cur2->next = head;
				cur2 = cur2->next;
			}
			head = head->next;
		}

		cur2->next = NULL;
		cur1->next = dummy2->next;

		return dummy1->next;
	}
};