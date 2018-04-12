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
	int maxPathSum(TreeNode *root) {
		if (root == NULL) return 0;
		res = INT_MIN;
		helper(root);
		return res;

	}
	int helper(TreeNode* root){
		if (root == NULL) return 0;
		int left = max(0, helper(root->left));
		int right = max(0, helper(root->right));
		res = max(res, left + right + root->val);
		return max(left, right) + root->val;
	}
private:
	int res;
};