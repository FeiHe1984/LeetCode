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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int>> res;
		vector<int> list;
		if (root == NULL) return res;
		helper(res, list, root, sum);
		return res;
	}

	void helper(vector<vector<int>>& res, vector<int>& list, TreeNode* root, int sum){
		if (root == NULL) return;
		list.push_back(root->val);
		if (root->left == NULL && root->right == NULL){
			if (sum == root->val){
				res.push_back(list);
			}
		}
		helper(res, list, root->left, sum - root->val);
		helper(res, list, root->right, sum - root->val);
		list.pop_back();
	}
};