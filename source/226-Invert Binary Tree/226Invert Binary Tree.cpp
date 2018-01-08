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
    TreeNode* invertTree(TreeNode* root) {
        if(nullptr == root)
            return root;
        TreeNode *p = nullptr;
	    while (root->left != nullptr || nullptr != root->right)
	    {
		    invertTree(root->left);
		    invertTree(root->right);
		    p = root->left;
		    root->left = root->right;
		    root->right = p;
		    break;
	    }
	    return root;
    }
};