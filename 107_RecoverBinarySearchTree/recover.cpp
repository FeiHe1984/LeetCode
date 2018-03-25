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
	bool isValidBST(TreeNode *root) {
		return helper(root, INT_MIN, INT_MAX);
	}

	bool helper(TreeNode * root, int lower, int upper) {
		if (!root) {
			return true;
		}
		if (root->val <= lower || root->val >= upper)    return false;
		return (helper(root->left, lower, root->val) && helper(root->right, root->val, upper));
	}
};