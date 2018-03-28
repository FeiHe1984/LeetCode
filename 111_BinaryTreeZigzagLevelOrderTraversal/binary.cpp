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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > res;
		if (root == NULL) return res;
		deque<TreeNode*> dq;
		bool leftToRight = true;
		dq.push_back(root);
		while (dq.size()){
			int size = dq.size();
			vector<int> clist;
			if (leftToRight){
				for (int i = 0; i < size; i++){
					TreeNode* curr = dq.front();
					dq.pop_front();
					if (curr->left) dq.push_back(curr->left);
					if (curr->right) dq.push_back(curr->right);
					clist.push_back(curr->val);
				}
			}
			else{
				for (int i = 0; i < size; i++){
					TreeNode* curr = dq.back();
					dq.pop_back();
					if (curr->right) dq.push_front(curr->right);
					if (curr->left) dq.push_front(curr->left);
					clist.push_back(curr->val);
				}
			}
			res.push_back(clist);
			leftToRight = !leftToRight;
		}
		return res;
	}
};