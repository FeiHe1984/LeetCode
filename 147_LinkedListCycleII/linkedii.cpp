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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return NULL;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow){
				ListNode* slow2 = head;
				while (slow != slow2){
					slow = slow->next;
					slow2 = slow2->next;
				}
				return slow;
			}
		}
		return NULL;
	}
};