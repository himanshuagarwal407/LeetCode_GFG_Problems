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
    int solve(TreeNode* root)
    {
        int count=0;
        
        if(root->left)
        {
            if(root->left->val>=root->val)
                count += 1+solve(root->left);
            else
            {
                root->left->val=root->val;
                count += solve(root->left);
            }
        }
        if(root->right)
        {
            if(root->right->val>=root->val)
                count+=1+solve(root->right);
            else
            {
                root->right->val=root->val;
                count += solve(root->right);
            }
        }
        
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        int count=1;
        
        count += solve(root);
        
        return count;
    }
};