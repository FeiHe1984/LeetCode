#include<iostream>
#include<cstring>
using namespace std;
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution{
public:
    int maxDepth(TreeNode* root){
        if(NULL == root) return 0;

        int depth_l = maxDepth(root->left);
        int depth_r = maxDepth(root->right);

        return depth_l > depth_r ? depth_l + 1:depth_r + 1;
    }
};
