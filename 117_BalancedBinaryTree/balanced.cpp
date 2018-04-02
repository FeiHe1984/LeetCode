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
	bool isBalanced(TreeNode *root) {
		if (root == NULL) return true;
		return(treeHeight(root) != -1);

	}
	int treeHeight(TreeNode* root){
		if (root == NULL) return 0;
		int leftDepth = treeHeight(root->left);
		int rightDepth = treeHeight(root->right);
		if (leftDepth == -1 || rightDepth == -1) return -1;
		if (abs(leftDepth - rightDepth) > 1) return -1;
		return (max(leftDepth, rightDepth) + 1);
	}
};