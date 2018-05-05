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
	ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* middle = getMiddle(head);
		ListNode* next = middle->next;
		middle->next = NULL;
		return merge(sortList(head), sortList(next));
	}

	ListNode* getMiddle(ListNode* head){
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next != NULL && fast->next->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	ListNode* merge(ListNode* a, ListNode* b){
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;

		while (a != NULL && b != NULL){
			if (a->val <= b->val){
				cur->next = a;
				a = a->next;
			}
			else{
				cur->next = b;
				b = b->next;
			}
			cur = cur->next;
		}
		if (a == NULL) cur->next = b;
		else cur->next = a;
		return dummy->next;
	}

};