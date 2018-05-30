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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (root == NULL) return res;

		deque<TreeNode*> dequeTreeNode;
		dequeTreeNode.push_back(root);

		while (dequeTreeNode.size()){
			TreeNode* pNode = dequeTreeNode.front();
			dequeTreeNode.pop_front();

			res.push_back(pNode->val);

			if (pNode->left){
				dequeTreeNode.push_back(pNode->left);
			}
			if (pNode->right){
				dequeTreeNode.push_back(pNode->right);
			}
		}
		return res;
	}
};