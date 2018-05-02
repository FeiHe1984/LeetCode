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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode* > s;
		if (root == NULL) return res;

		s.push(root);
		while (!s.empty()){
			TreeNode* cur = s.top();
			s.pop();
			if (cur->right != NULL) s.push(cur->right);
			if (cur->left != NULL) s.push(cur->left);
			res.push_back(cur->val);
		}
		return res;

	}
};