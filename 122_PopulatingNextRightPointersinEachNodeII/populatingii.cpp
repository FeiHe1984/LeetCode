/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode* head = NULL;
		TreeLinkNode* pre = NULL;
		TreeLinkNode* cur = root;

		while (cur != NULL){
			while (cur != NULL){
				if (cur->left != NULL){
					if (pre != NULL) pre->next = cur->left;
					else head = cur->left;
					pre = cur->left;
				}
				if (cur->right != NULL){
					if (pre != NULL) pre->next = cur->right;
					else head = cur->right;
					pre = cur->right;
				}
				cur = cur->next;

			}
			cur = head;
			pre = NULL;
			head = NULL;
		}
	}
};