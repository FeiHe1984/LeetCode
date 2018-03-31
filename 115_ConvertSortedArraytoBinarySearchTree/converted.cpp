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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (num.empty()) return NULL;
		int left = 0, right = num.size() - 1;
		return helper(num, left, right);
	}

	TreeNode* helper(vector<int>& num, int left, int right){
		if (left > right) return NULL;
		int mid = (left + right + 1) / 2;
		TreeNode* node = new TreeNode(num[mid]);
		node->left = helper(num, left, mid - 1);
		node->right = helper(num, mid + 1, right);
		return node;
	}
};