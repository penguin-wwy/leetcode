/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (nullptr == root)
		    return root;
	    if (nullptr == root->left && nullptr == root->right)
	    	return sum == root->val;

	    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};