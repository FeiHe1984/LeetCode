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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode *head = new ListNode(-1);
		ListNode *cur = head;

		while (l1 != NULL && l2 != NULL){
			bool chk = (l1->val < l2->val);
			cur->next = chk ? l1 : l2;
			cur = cur->next;
			l1 = chk ? l1->next : l1;
			l2 = chk ? l2 : l2->next;
		}
		cur->next = (l1 == NULL) ? l2 : l1;
		return head->next;
	}
};