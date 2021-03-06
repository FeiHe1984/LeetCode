/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (head == NULL) return NULL;
		return toBST(head, NULL);

	}
	TreeNode* toBST(ListNode* head, ListNode* tail){
		if (head == tail) return NULL;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != tail && fast->next != tail){
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* root = new TreeNode(slow->val);
		root->left = toBST(head, slow);
		root->right = toBST(slow->next, tail);
		return root;
	}
};