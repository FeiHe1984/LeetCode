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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		if (root == NULL) return res;

		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()){
			TreeNode* cur = s.top();
			s.pop();
			res.insert(res.begin(), cur->val);
			if (cur->left != NULL) s.push(cur->left);
			if (cur->right != NULL) s.push(cur->right);
		}
		return res;
	}
};