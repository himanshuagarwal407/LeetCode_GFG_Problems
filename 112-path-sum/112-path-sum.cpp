/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool pathSum(TreeNode* root, int targetSum)
    {
        if(!root)
            return false;
        
        if(targetSum==root->val && !root->left && !root->right)
            return true;
        
        return pathSum(root->left, targetSum-root->val) || pathSum(root->right, targetSum-root->val);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        return pathSum(root, targetSum);
    }
};