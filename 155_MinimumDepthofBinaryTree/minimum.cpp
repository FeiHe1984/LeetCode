class Solution {
public:
	int run(TreeNode *root) {
		if (root == NULL) return 0;
		if (root->left == NULL) return run(root->right) + 1;
		else if (root->right == NULL) return run(root->left) + 1;
		return min(run(root->left), run(root->right)) + 1;
	}
};