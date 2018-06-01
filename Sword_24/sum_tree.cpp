/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> res;
		vector<int> temp;
		int currentSum = 0;

		dfs(root, expectNumber, res, temp, currentSum);
		return res;
	}

	void dfs(TreeNode* root, int expectNumber, vector<vector<int>> &res, vector<int> &temp, int &currentSum){
		if (root == NULL) return;
		currentSum += root->val;
		temp.push_back(root->val);

		if (!root->left && !root->right){
			if (currentSum == expectNumber){
				res.push_back(temp);
			}
		}

		if (root->left) dfs(root->left, expectNumber, res, temp, currentSum);
		if (root->right) dfs(root->right, expectNumber, res, temp, currentSum);

		currentSum -= root->val;
		temp.pop_back();
	}
};