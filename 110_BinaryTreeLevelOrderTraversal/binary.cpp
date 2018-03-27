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
	vector<vector<int> > levelOrder(TreeNode *root) {

		vector<vector<int>>vec;
		if (root == NULL)return vec;
		queue<TreeNode*>q;
		queue<int>lev;
		q.push(root);
		lev.push(0);
		TreeNode*p;
		int layer = 0;
		while (q.empty() == false){
			p = q.front();
			layer = lev.front();
			q.pop();
			lev.pop();
			if (vec.size()<layer + 1){
				vector<int>vt;
				vec.push_back(vt);
			}
			vec[layer].push_back(p->val);
			if (NULL != p->left)q.push(p->left), lev.push(layer + 1);
			if (p->right != NULL)q.push(p->right), lev.push(layer + 1);
		}
		return vec;
	}
};