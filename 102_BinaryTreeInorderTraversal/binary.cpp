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
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		if (root == NULL) return res;
		DFS(root, res);
		return res;
	}
	void DFS(TreeNode* node, vector<int>& list){
		if (node == NULL) return;
		DFS(node->left, list);
		list.push_back(node->val);
		DFS(node->right, list);
	}
};