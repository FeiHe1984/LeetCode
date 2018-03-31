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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > res;
		if (root == NULL) return res;
		queue<TreeNode*> que;
		que.push(root);
		while (que.size() != 0){
			vector<int> tmpRes;
			queue<TreeNode*> tmpQue;
			while (que.size() != 0){
				TreeNode* node = que.front();
				que.pop();
				if (node->left) tmpQue.push(node->left);
				if (node->right) tmpQue.push(node->right);
				tmpRes.push_back(node->val);
			}
			res.push_back(tmpRes);
			que = tmpQue;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};