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
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode* dummy = new ListNode(0);

		ListNode* preNode = dummy;
		ListNode* curNode = head;
		ListNode* realNode = dummy;

		while (curNode != NULL){
			if ((preNode == dummy || preNode->val != curNode->val) && (curNode->next == NULL || curNode->val != curNode->next->val)){
				realNode->next = curNode;
				realNode = curNode;
			}
			preNode = curNode;
			curNode = curNode->next;
			preNode->next = NULL;
		}
		return dummy->next;
	}
};