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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.size() == 0 || inorder.size() == 0) return NULL;
		return buildTreeHelper(preorder, inorder, 0, 0, preorder.size() - 1);

	}

	TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int pre_st, int in_st, int in_end){
		if (pre_st >= preorder.size() || in_st > in_end) return NULL;
		TreeNode* curr = new TreeNode(preorder[pre_st]);
		int i = in_st;
		while (i <= in_end){
			if (inorder[i] == preorder[pre_st]) break;
			i++;
		}

		curr->left = buildTreeHelper(preorder, inorder, pre_st + 1, in_st, i - 1);
		curr->right = buildTreeHelper(preorder, inorder, pre_st + (i - in_st + 1), i + 1, in_end);

		return curr;
	}
};