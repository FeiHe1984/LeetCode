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
	int sumNumbers(TreeNode *root) {
		return helper(root, 0);

	}
	int helper(TreeNode* root, int num){
		if (root == NULL) return 0;
		if (root->left == NULL && root->right == NULL){
			return num * 10 + root->val;
		}
		return helper(root->left, num * 10 + root->val) + \
			helper(root->right, num * 10 + root->val);
	}
};