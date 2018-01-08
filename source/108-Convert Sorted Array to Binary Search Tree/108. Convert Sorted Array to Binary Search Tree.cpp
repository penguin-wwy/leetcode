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
    TreeNode* generateBST(int left, int right, vector<int>& nums) {
        if(left > right)
            return nullptr;
        if(left == right)
            return new TreeNode(nums[left]);
        else{
            TreeNode *node = new TreeNode(nums[(left + right) / 2]);
            node->left = generateBST(left, (left + right) / 2 - 1, nums);
            node->right = generateBST((left + right) / 2 + 1, right, nums);
            return node;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        else 
            return generateBST(0, nums.size() - 1, nums);
    }
};