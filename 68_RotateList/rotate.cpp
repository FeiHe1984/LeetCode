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
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL) return head;
		ListNode *fast = head;
		ListNode *slow = head;
		int len = 0;
		while (fast != NULL){
			len++;
			fast = fast->next;
		}
		fast = head;
		for (int i = 0; i < k % len; i++){
			fast = fast->next;
		}
		while (fast->next != NULL){
			fast = fast->next;
			slow = slow->next;
		}
		fast->next = head;
		head = slow->next;
		slow->next = NULL;
		return head;
	}
};